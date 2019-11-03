# flora-vs-undead
# Development process
![Alt text](assets/devproc.jpg?raw=true "Title")

## 1. Create feature branch
* make sure you are creating feature branch from develop branch 
	* bash
		* git status - shows status and current branch
		* git checkout -b <branchname> - creates new branch from current branch
	* [UI](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-and-deleting-branches-within-your-repository)


## 2. Commit and push chnages to new feature branch
* bash
	* git status - shows status and chnages made to files
	* git add <filename> - add file for commit
	* git commit -m "message" - commits the added files and 
	* git push - uploads files to origin repository
* [UI](https://help.github.com/en/desktop/contributing-to-projects/committing-and-reviewing-changes-to-your-project)

#### (never use force for push)

## 3. Open pull request form feature branch to develop branch
* [UI](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request)
## 4. After aprooval merge feature branch to develop branch
	- resole any confilct if needed

## 5. On weekly meeting aproove and merge develop branch to master branch



