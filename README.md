# Automated LeetCode to GitHub Submission Sync

This repository is a backend automation tool that tracks accepted
LeetCode submissions and syncs them into a private GitHub repository
without manual intervention. The pipeline runs entirely inside GitHub
Actions, so there is no dedicated server, no local daemon, and no third-
party hosting service to maintain.

Every 15 minutes, a scheduled workflow checks LeetCode for new accepted
submissions. When it finds one, it fetches the solution code and the
problem metadata, then writes a new folder under `problems/` named by
the problem number and slug, for example:

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

## How It Works

- The workflow runs on GitHub's infrastructure only.
- It uses repository secrets for `LEETCODE_SESSION` and
  `LEETCODE_CSRF_TOKEN`.
- It commits only when new accepted submissions are found.
- It persists sync state in `.synced_submissions.json` so previously
  recorded submissions are not written again.

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

### 2. Get your LeetCode session cookie

1. Log into leetcode.com in your browser.
2. Open DevTools → Application (Chrome) / Storage (Firefox) → Cookies →
   `https://leetcode.com`.
3. Copy the values of `LEETCODE_SESSION` and `csrftoken`.

These expire every few weeks — when they do, the workflow will fail
with a clear "session expired" message in the Actions log, and you
just repeat this step with fresh values.

### 3. Add them as repo secrets

In your new GitHub repo: **Settings → Secrets and variables → Actions →
New repository secret**. Add two secrets:

- `LEETCODE_SESSION` → the value you copied
- `LEETCODE_CSRF_TOKEN` → the csrftoken value you copied

No GitHub token needed. The workflow uses GitHub's
own built-in `GITHUB_TOKEN`, automatically scoped to just this repo.

### 4. Turn it on

Go to the **Actions** tab in your repo. If prompted, click "I understand
my workflows, enable them." The workflow will now run automatically
every 15 minutes.

To confirm it works right away rather than waiting: Actions tab →
"Sync LeetCode submissions" → **Run workflow** (this is the
`workflow_dispatch` trigger, runs it on demand).

## Notes

- 15 minutes is the schedule interval — GitHub Actions cron is
  best-effort, so actual runs may land a few minutes off schedule.
  You can lower it (e.g. `*/5 * * * *`) if you want, but GitHub may
  still throttle very frequent schedules.
- GitHub disables scheduled workflows automatically after 60 days of
  repo inactivity (no commits). Pushing anything, including the bot's
  own commits, resets that clock — so as long as you're solving
  problems, it stays active on its own.
- The only external service this ever talks to is `leetcode.com`,
  using the same undocumented endpoints the LeetCode website itself
  uses (there's no official public API). If LeetCode changes them,
  `scripts/sync.py` may need small updates.
- Nothing runs on your machine or any paid host — the free tier of
  GitHub Actions (2,000 minutes/month on free accounts) comfortably
  covers a job this small running every 15 minutes.
