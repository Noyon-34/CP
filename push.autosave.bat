@echo off
DATE=$(date "+%Y-%m-%d %H:%M:%S")

git add .

GIT_AUTHOR_DATE="$DATE" \
GIT_COMMITTER_DATE="$DATE" \
git commit -m "daily cp practice"

git push