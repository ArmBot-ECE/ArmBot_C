# Branch/Collaboration

Code must implemented in specific git branches. Then create a **Pull Request** pointing to **Master**.

### Create and switch branch

Change branch using:

`$ git checkout <existing_branch>`

Create a new branch and directly switch to it:

`$ git checkout -b <new_branch>`

Push the branch on github:

`$ git push origin <name_of_your_new_branch>`

More info [Basic Branching and Merging](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging)

# Synchronize your branch

As said before, you must not work directly on **master**, but create your own branch and implement code in it.
If necessary, you can synchronize your branch with **master** in order to fetch the last stable of **master**.

`git pull origin master`

# Commit changes

Simply use:

`$ git commit -m "Your message here"`


# Merge branches

Please read [Basic Branching and Merging](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging)
