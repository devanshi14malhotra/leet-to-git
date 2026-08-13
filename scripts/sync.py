#!/usr/bin/env python3
"""
sync.py

Fetches your recent accepted LeetCode submissions and writes any new ones
to disk under problems/{number}-{slug}/. It does NOT talk to GitHub at all
— when run inside the GitHub Actions workflow, the workflow itself commits
and pushes whatever files this script creates or changes. When run locally,
you'd commit/push manually.

Required environment variables:
    LEETCODE_SESSION      - your LeetCode session cookie
    LEETCODE_CSRF_TOKEN    - your LeetCode csrftoken cookie

See README.md for how to obtain these and where to set them.
"""

import os
import sys
import json
import time
import subprocess
import requests

LEETCODE_SESSION = os.environ.get("LEETCODE_SESSION")
LEETCODE_CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN")

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PROBLEMS_DIR = os.path.join(REPO_ROOT, "problems")
SYNC_LOG_PATH = os.path.join(REPO_ROOT, ".synced_submissions.json")

LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"
LEETCODE_SUBMISSIONS_URL = "https://leetcode.com/api/submissions/"

LANG_EXTENSIONS = {
    "python": "py", "python3": "py", "c": "c", "cpp": "cpp", "java": "java",
    "csharp": "cs", "javascript": "js", "typescript": "ts", "php": "php",
    "swift": "swift", "kotlin": "kt", "dart": "dart", "golang": "go",
    "ruby": "rb", "scala": "scala", "rust": "rs", "racket": "rkt",
    "erlang": "erl", "elixir": "ex", "mysql": "sql",
}


def require_config():
    missing = [n for n, v in [("LEETCODE_SESSION", LEETCODE_SESSION),
                               ("LEETCODE_CSRF_TOKEN", LEETCODE_CSRF_TOKEN)] if not v]
    if missing:
        print(f"Missing required environment variables: {', '.join(missing)}")
        sys.exit(1)


def leetcode_headers():
    return {
        "Cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}; csrftoken={LEETCODE_CSRF_TOKEN}",
        "x-csrftoken": LEETCODE_CSRF_TOKEN,
        "Referer": "https://leetcode.com",
        "Content-Type": "application/json",
    }


def load_sync_log():
    if os.path.exists(SYNC_LOG_PATH):
        with open(SYNC_LOG_PATH, "r") as f:
            return set(json.load(f))
    return set()


def save_sync_log(ids):
    with open(SYNC_LOG_PATH, "w") as f:
        json.dump(sorted(ids), f, indent=2)


def fetch_recent_accepted_submissions(limit=100):
    submissions = []
    offset = 0

    while True:
        resp = requests.get(
            LEETCODE_SUBMISSIONS_URL,
            params={"offset": offset, "limit": limit},
            headers=leetcode_headers(),
            timeout=15,
        )
        if resp.status_code == 401:
            print("LeetCode session expired or invalid — refresh LEETCODE_SESSION / LEETCODE_CSRF_TOKEN secrets.")
            sys.exit(1)
        resp.raise_for_status()

        page = resp.json().get("submissions_dump", [])
        if not page:
            break

        submissions.extend(s for s in page if s.get("status_display") == "Accepted")

        if len(page) < limit:
            break

        offset += limit

    return submissions


def fetch_submission_details(submission_id):
    query = """
    query submissionDetails($submissionId: Int!) {
        submissionDetails(submissionId: $submissionId) {
            code
            lang { name }
            question {
                questionFrontendId
                titleSlug
                title
                difficulty
                topicTags { name }
            }
        }
    }
    """
    resp = requests.post(
        LEETCODE_GRAPHQL_URL,
        headers=leetcode_headers(),
        json={"query": query, "variables": {"submissionId": int(submission_id)}},
        timeout=15,
    )
    resp.raise_for_status()
    return resp.json().get("data", {}).get("submissionDetails")


def problem_folder_name(question):
    return f"{question.get('questionFrontendId', '0')}-{question.get('titleSlug', 'unknown')}"


def build_problem_readme(question):
    tags = ", ".join(t["name"] for t in question.get("topicTags", []))
    return (
        f"# {question['questionFrontendId']}. {question['title']}\n\n"
        f"**Difficulty:** {question['difficulty']}\n\n"
        f"**Topics:** {tags}\n\n"
        f"[View on LeetCode](https://leetcode.com/problems/{question['titleSlug']}/)\n"
    )


def git(*args):
    subprocess.run(["git", *args], cwd=REPO_ROOT, check=True)


def commit_problem(question):
    message = f"LeetCode submission: problem {question['questionFrontendId']} - {question['title']}"
    git("add", "-A")
    git("commit", "-m", message)


def main():
    require_config()
    synced_ids = load_sync_log()

    submissions = fetch_recent_accepted_submissions(limit=20)
    new_submissions = [s for s in submissions if str(s["id"]) not in synced_ids]

    if not new_submissions:
        print("No new accepted submissions.")
        return

    print(f"Found {len(new_submissions)} new accepted submission(s).")
    written = 0

    for sub in reversed(new_submissions):  # oldest first
        sub_id = str(sub["id"])
        details = fetch_submission_details(sub_id)
        if not details:
            print(f"  ! Could not fetch details for submission {sub_id}, skipping this run.")
            continue

        question = details["question"]
        folder = problem_folder_name(question)
        folder_path = os.path.join(PROBLEMS_DIR, folder)
        os.makedirs(folder_path, exist_ok=True)

        ext = LANG_EXTENSIONS.get(details["lang"]["name"].lower(), "txt")
        with open(os.path.join(folder_path, f"solution.{ext}"), "w") as f:
            f.write(details["code"])
        with open(os.path.join(folder_path, "README.md"), "w") as f:
            f.write(build_problem_readme(question))

        print(f"  -> wrote problems/{folder}/")
        synced_ids.add(sub_id)
        save_sync_log(synced_ids)
        commit_problem(question)
        written += 1
        time.sleep(1)  # be gentle on LeetCode's API
    print(f"Done. {written} new problem(s) written.")


if __name__ == "__main__":
    main()
