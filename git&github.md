---

# 🚀 Git & GitHub Full Command List (with Explanations)

---

## ✅ 1. **Git Setup (First Time Only)**

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

> Sets your Git identity globally (for all projects).

---

## ✅ 2. **Start a Git Project**

```bash
git init
```

> Initializes a new Git repository in your project folder.

---

## ✅ 3. **Connect to GitHub**

```bash
git remote add origin https://github.com/username/repo-name.git
```

> Links your local project to a GitHub repository.

---

## ✅ 4. **Staging and Committing**

```bash
git add .
git commit -m "Your commit message"
```

> Stages all changes and commits with a message.

---

## ✅ 5. **Pushing to GitHub**

```bash
git branch -M main      # Rename current branch to main (if not already)
git push -u origin main
```

> Pushes your code to GitHub on the `main` branch.

---

## ✅ 6. **Pulling from GitHub**

```bash
git pull origin main
```

> Downloads the latest changes from GitHub.

---

## ✅ 7. **Cloning a GitHub Repo**

```bash
git clone https://github.com/username/repo-name.git
```

> Copies a remote GitHub repo to your local machine.

---

## ✅ 8. **Check Status**

```bash
git status
```

> Shows which files are staged, modified, or untracked.

---

## ✅ 9. **Check Git History**

```bash
git log
```

> Shows commit history (press `q` to exit).

---

## ✅ 10. **See Branches**

```bash
git branch
```

> Lists all local branches.

---

## ✅ 11. **Create & Switch Branch**

```bash
git checkout -b new-branch
```

> Creates and switches to `new-branch`.

---

## ✅ 12. **Switch to Existing Branch**

```bash
git checkout branch-name
```

---

## ✅ 13. **Merge Branch**

```bash
git checkout main
git merge branch-name
```

> Merges changes from `branch-name` into `main`.

---

## ✅ 14. **Delete a Branch**

```bash
git branch -d branch-name
```

---

## ✅ 15. **Remove Remote URL**

```bash
git remote remove origin
```

---

## ✅ 16. **Change Remote URL**

```bash
git remote set-url origin https://github.com/username/new-repo.git
```

---

## ✅ 17. **Solve: Dubious Ownership Error**

```bash
git config --global --add safe.directory 'your/project/path'
```

> Trusts the folder even if Git thinks it’s unsafe.

---

## ✅ 18. **Force Push (Be Careful)**

```bash
git push --force
```

> Rewrites history on GitHub — use only if necessary.

---

## ✅ 19. **Discard Local Changes**

```bash
git restore filename
```

> Discards changes in a file.

```bash
git restore --staged filename
```

> Removes a file from staging area.

---

## ✅ 20. **See Remote Info**

```bash
git remote -v
```

---

## ✅ 21. **Undo Last Commit (Safe)**

```bash
git reset --soft HEAD~1
```

> Keeps your changes, removes last commit.

---

## ✅ 22. **Remove All Caches**

```bash
git rm -r --cached .
```

> Useful when fixing `.gitignore` issues.

---

## ✅ 23. **Git Ignore File**

Create a `.gitignore` file and add things like:

```
node_modules/
.env
.DS_Store
```

> Prevents these from being pushed to GitHub.

---

## ✅ 24. **Git Clean (Remove Untracked Files)**

```bash
git clean -fd
```

> Be careful — deletes untracked files and folders!

---

## ✅ 25. **Tag a Commit (Versioning)**

```bash
git tag v1.0
git push origin v1.0
```

---

## ✅ 26. **Check Git Version**

```bash
git --version
```

---

## ✅ 27. **Get Help on Any Git Command**

```bash
git help command-name
# Example:
git help push
```

---

## 💥 Bonus: GitHub Error Solutions

| ❌ Error                       | ✅ Solution                                            |
| ----------------------------- | ----------------------------------------------------- |
| Dubious ownership             | `git config --global --add safe.directory 'path'`     |
| Remote origin already exists  | `git remote remove origin` then add again             |
| Permission denied (publickey) | Check SSH key or use HTTPS URL                        |
| Merge conflict                | Open file, fix conflict, `git add .` and `git commit` |
| Rejected non-fast-forward     | Use `git pull --rebase` or `git push --force`         |

---


You’re now ready to work like a pro on Git & GitHub!
Let me know if you want this customized for **React**, **Node.js**, or **Team Collaboration**.
