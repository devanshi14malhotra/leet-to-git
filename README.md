# Automated LeetCode to GitHub Submission Sync

This repository is a backend automation tool that tracks accepted
LeetCode submissions and syncs them into a private GitHub repository
without manual intervention. The normal pipeline runs inside GitHub
Actions, so there is no dedicated server, local daemon, or manual push
required when Actions can reach LeetCode.

Every 15 or 30 minutes, a scheduled workflow checks LeetCode for new accepted
submissions. When it finds one, it fetches the solution code and the
problem metadata, then writes a new folder under `problems/` named by
the problem number and slug, for example:-

```
problems/1-two-sum/solution.py
problems/1-two-sum/README.md
```

Each generated entry includes the solution code plus metadata such as
difficulty and topic tags.

## Repository Layout

- `.github/workflows/sync.yml` runs the automation on a schedule and
  commits any generated changes back to the repo.
- `scripts/sync.py` is the sync script that polls LeetCode, filters to
  accepted submissions, fetches the code and metadata, and writes the
  files into `problems/{number}-{slug}/`.
- `problems/` is the output directory for synced solutions and per-
  problem readmes.
- `requirements.txt` lists the Python dependency used by the sync
  script.

## V1 and V2

### V1: REST submissions endpoint

The original implementation requested accepted submissions from
`/api/submissions/`, using the authenticated `LEETCODE_SESSION` and
`LEETCODE_CSRF_TOKEN` cookies. It then used GraphQL to fetch each
submission's code and metadata.

V1 worked automatically from GitHub Actions until LeetCode/Cloudflare began
returning `403 Forbidden` responses for the GitHub-hosted runner. This was
an access-blocking problem, not a workflow scheduling problem.

### V2: GraphQL submissions query

The current implementation uses LeetCode GraphQL for the accepted-submission
list and for submission details. It uses:

- `LEETCODE_USERNAME` to identify the profile. It is read from GitHub
  Actions repository secrets so no account identifier is committed here.
- `LEETCODE_SESSION` and `LEETCODE_CSRF_TOKEN` to authenticate access to
  private submission code and details.

V2 preserves the original behavior: the scheduled workflow checks for new
accepted submissions, processes them oldest first, creates one Git commit per
submission, and pushes those commits to `main`.

V2 does **not** make the cookies permanent and does **not** guarantee that
GitHub-hosted runner IPs can pass LeetCode Cloudflare checks. If GraphQL
returns a `403`, the workflow still cannot sync until LeetCode allows that
request path or runner.

## Local Secrets

For local runs, keep your secrets in a root-level `.env` file. Use
`.env.example` as the starting point, copy it to `.env`, and fill in your
own values. The `.env` file is ignored by Git, so it stays on your
machine.

The sync script automatically loads `.env` when it exists, so you do not
need to export variables manually if you use that file.

## How It Works

- The workflow runs automatically on GitHub's infrastructure every two hours
  (`0 */2 * * *`) and can also be started manually.
- It uses repository secrets for `LEETCODE_SESSION`,
  `LEETCODE_CSRF_TOKEN`, and `LEETCODE_USERNAME`.
- It creates one commit per new accepted submission, using a message
  like `LeetCode submission: problem 704 - Binary Search`.
- It persists sync state in `.synced_submissions.json` so previously
  recorded submissions are not written again.

When the GitHub-hosted workflow is healthy, you only submit normally on
LeetCode. You do **not** need to run the script or push manually after every
submission. The next scheduled or manually triggered run fetches all new
accepted submissions since the previous successful run and pushes the
individual commits.

Running `python scripts/sync.py` locally is an optional troubleshooting or
recovery path. A successful local run creates commits in the local clone, so
you then run `git push origin main`; it does not replace the scheduled
workflow.

## Setup (one-time, ~5 minutes)

### 1. Create the repo

Create a new repo on GitHub (private or public, your choice) and push
this folder to it:

```bash
cd leet-to-git
git init
git add .
git commit -m "Initial setup"
git branch -M main
git remote add origin https://github.com/devanshi14malhotra/leet-to-git.git
git push -u origin main
```

### 2. Create your local `.env`

Copy `.env.example` to `.env` in the repo root, then replace the dummy
values with your own secrets and GitHub identity:

- `LEETCODE_SESSION` for your LeetCode session cookie
- `LEETCODE_CSRF_TOKEN` for your LeetCode csrf token
- `LEETCODE_USERNAME` for your LeetCode profile username
- `COMMIT_AUTHOR_NAME` for the commit author name you want on GitHub
- `COMMIT_AUTHOR_EMAIL` for a verified email on your GitHub account

If you prefer, you can use your GitHub no-reply email for
`COMMIT_AUTHOR_EMAIL`.

### 3. Get your LeetCode session cookie

1. Log into leetcode.com in your browser.
2. Open DevTools → Application (Chrome) / Storage (Firefox) → Cookies →
   `https://leetcode.com`.
3. Copy the values of `LEETCODE_SESSION` and `csrftoken`.

These expire every few weeks (often around two weeks, but the exact lifetime
is controlled by LeetCode). When they expire, update both values in the
locations where you use them:

1. The local `.env`, if you run the recovery path locally.
2. GitHub repository **Actions secrets**, if you want the scheduled workflow
   to keep running.

You do not need to update them after every submission. Only update them when
LeetCode stops authenticating the current values or the workflow reports an
authentication failure.

If the log says that Cloudflare blocked the GitHub-hosted runner, refreshing
these values will not help. LeetCode may challenge GitHub Actions IP ranges
even when the cookies are valid. Run the workflow on a self-hosted runner
with normal browser access, or run `python scripts/sync.py` locally from a
machine that can access LeetCode.

### 4. Add them as repo secrets

In your new GitHub repo: **Settings → Secrets and variables → Actions →
New repository secret**. Add three secrets:

- `LEETCODE_SESSION` → the value you copied
- `LEETCODE_CSRF_TOKEN` → the csrftoken value you copied

Also add `LEETCODE_USERNAME` under **Settings → Secrets and variables →
Actions → Repository secrets**. Although the username is not sensitive,
keeping it there avoids committing it to the repository. If your LeetCode
username changes later, update this secret; the session and CSRF secrets are
separate credentials. Do not commit your `.env` file.

No GitHub token needed. The workflow uses GitHub's
own built-in `GITHUB_TOKEN`, automatically scoped to just this repo.

### 5. Turn it on

Go to the **Actions** tab in your repo. If prompted, click "I understand
my workflows, enable them." The workflow will now run automatically every two hours.

To confirm it works right away rather than waiting: Actions tab →
"Sync LeetCode submissions" → **Run workflow** (this is the
`workflow_dispatch` trigger, runs it on demand).

### 6. Make commits count toward your contribution graph

GitHub only turns your squares green when the commits are authored by
an identity that GitHub recognizes as yours.

- The workflow now defaults to `Devanshi Malhotra <malhotra.dm07@gmail.com>`.
- If your GitHub account uses a different verified email, add repository
  variables `COMMIT_AUTHOR_NAME` and `COMMIT_AUTHOR_EMAIL` in
  **Settings → Secrets and variables → Actions → Variables**.
- If the repo is private, make sure private contributions are enabled in
  your GitHub profile settings, or private commits will not show on the
  graph.

## Notes

- Two hours is the current schedule interval — GitHub Actions cron is
  best-effort, so actual runs may land a few minutes off schedule.
  You can change the cron expression in `.github/workflows/sync.yml` if
  needed.
- GitHub disables scheduled workflows automatically after 60 days of
  repo inactivity (no commits). Pushing anything, including the bot's
  own commits, resets that clock — so as long as you're solving
  problems, it stays active on its own.
- The only external service this ever talks to is `leetcode.com`,
  using the same undocumented endpoints the LeetCode website itself
  uses (there's no official public API). If LeetCode changes them,
  `scripts/sync.py` may need small updates.
- Nothing runs on your machine or any paid host when the GitHub-hosted
  workflow is available. The free tier of GitHub Actions covers a job this
  small, subject to GitHub account limits and LeetCode access decisions.
