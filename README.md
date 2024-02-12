# 5327B-OU  

## Git commands
The following tutorial on using git to interact with your codebase requires:  
- Git to be installed on your laptop  
- A separate folder within your desktop to host any and all of your GitHub-linked projects  

Make sure all git commands are entered in the `bash` terminal within VS Code.  

### Update your local branch with repo ( git pull )  
To get the latest version of the code from the repository, use `git pull`.  

### Saving your changes ( git add -A  &  git commit -m )  
To stage all changes (local save), use `git add -A`.  
  
To save a complete set of changes in a commit, use `git commit -m "Commit Message"`. Alternatively, go to the Source Control tab on the sidebar and press the commit button.  
DO NOT commit your changes without a brief, informative message explaining the changes in the text box above the commit button.  

### Syncing your commits to the repo ( git push )  
To publish your changes to the repository for all, use `git push` or press the blue "Sync changes" button.  

### Switching branches ( git checkout -b )  
To switch to a different branch of development, use `git checkout -b <branch_name>`.  

### Creating local copy of repo ( git clone <repo_link> )  
To create a local copy of a pre-existing repository, use the green "Code" button to get the github link of the repository.  
Then, use `git clone <repo_link>` to create a local clone of the repo to work on.

## VS Code Extensions  
### Required  
- C/C++  
- PROS  
### Recommended  
- GitHub Repositories  
- Remote Repositories  
- Live Share  
- Doxygen Documentation Generator  
- GitHub Pull Requests and Issues  

  
! Note: README.md files use Markdown syntax !  








# LemLib

Welcome to LemLib! This open-source PROS template aims to introduce common algorithms like Pure Pursuit and Odometry for new and experienced teams alike.

LemLib only supports differential drivetrains.

The creation of this template was inspired by [EZ-Template](https://github.com/EZ-Robotics/EZ-Template) and [OkapiLib](https://github.com/OkapiLib/OkapiLib). We aim to develop a library that strikes a balance between ease-of-use, akin to that of EZ-Template, and comprehensive functionality, similar to that of OkapiLib.

Want a place to chat with the devs and other users? Join our [discord server](https://discord.gg/pCHr7XZUTj).

## License

This project is licensed under the MIT license. Check [LICENSE](https://github.com/LemLib/LemLib/blob/master/LICENSE) for more details.

## Features
- Generic PID class
- Odometry
- Odom turn to face point
- [Boomerang controller](https://www.desmos.com/calculator/sptjw5szex)
- Pure Pursuit
- [Path Generator](https://github.com/LemLib/Path-Gen) support

## Tutorials
The tutorials provide a detailed walkthrough through all the features of LemLib. It covers everything from installation to pure pursuit.
 - 1: [Getting Started](https://lemlib.github.io/LemLib/md_docs_tutorials_1_getting_started.html)
 - 2: [Setting up the Chassis](https://lemlib.github.io/LemLib/md_docs_tutorials_2_setting_up_the_chassis.html)
 - 3: [Tuning and Moving](https://lemlib.github.io/LemLib/md_docs_tutorials_3_tuning_and_moving.html)
 - 4: [Pure Pursuit](https://lemlib.github.io/LemLib/md_docs_tutorials_4_pure_pursuit.html)

## Documentation
Check out the Doxygen documentation [here](https://lemlib.github.io/LemLib/index.html)

## Contributing
Want to contribute? Please read [CONTRIBUTING.md](https://github.com/LemLib/LemLib/blob/master/.github/CONTRIBUTING.md)

## Code of Conduct
See the [Code of Conduct](https://github.com/LemLib/LemLib/blob/master/.github/CODE_OF_CONDUCT.md) on how to behave like an adult.
