# TDD_ForEmbeddedC
Repo for learning TDD using the book "Test-Driven Development for Embedded C" by James W. Grenning

- Using Unity v2.6.0
- Using CppUtest v4.0

## Building Unity/CppUTest using CMake tools for VS Code on MSYS2 or WSL2 for TDD

### WSL2 Setup

Setting up a development machine using WSL2 is very straight forward. 

- Install WSL2 and the latest Ubuntu distro [How to install Linux on Windows with WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
    - Be sure to create a username (don't use root user) and password [Best practices for setting up a WSL dev environment](https://learn.microsoft.com/en-us/windows/wsl/setup/environment#set-up-your-linux-username-and-password)
    - apt-get -y install gcovr git git-lfs cmake ninja-build
- Once all of that is done we can clone the unit testing frame works from the book.
    - Clone Unity [Unity GitHub](https://github.com/ThrowTheSwitch/Unity) to your desired location.
        - Create a persistent environemnt var **UNITY_HOME** which points to root folder of repo.
        - switch to tag for v2.6.0
    - Clone CppUTest [CppUTest GitHub](https://github.com/cpputest/cpputest) to your desired location.
        - Create a persistent environment var **CPPUTEST_HOME** which points to root folder of repo.
        - switch to tag for v4.0
    - [Environment Variables on Ubuntu](https://help.ubuntu.com/community/EnvironmentVariables)
        - Scroll down to section on **Persistent environment variables**.
    - To make this development environment a little more user friendly, I recommned reviewing the following: 
        - [Developing in WSL with VS Code](https://code.visualstudio.com/docs/remote/wsl)
            - Documents how to setup VS Code for developing on WSL2
        - [CMake Tools Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
            - Extension for VS code providing a UI for using the tool.
        - [CppUTest Adapter Extension](https://marketplace.visualstudio.com/items?itemName=bneumann.cpputest-test-adapter)
            - Extension for VS code providing a UI for running unit tests.  A launch.json has also been provided for debugging unit tests from the UI.

- List of tools used and their versions
    - distro  Ubuntu 22.04.3 LTS jammy (use lsb_release -a at cmd line to get) 
    - Ninja   1.10.1 
    - CMake   3.22.1 
    - Doxygen 1.9.1 
    - gcovr   5.0 

### MSYS2 Setup

Please **don not** use git bash for this.  Git for Windows installs its own mingw environment to allow Windows users to use git.  That environment is under the control of the Git for Windows installer and updater.  I don't think it is a good idea to install additional packages in that environment and expect them to be managed through updates, [see link](https://superuser.com/questions/1294343/install-gcc-in-git-for-windows-bash-environment).  I maybe mistaken, however, I didn't look into that and it just seems problematic to me.

Below, the steps to setup your MSYS2 environment reference the UCRT environment.  Please visit the following link to understand why [MSYS2 Environments](https://www.msys2.org/docs/environments/).

Additionally, if you already have CMake installed directly on Windows and then install CMake in the UCRT environment, this may give you some trouble when using the CMake extension for VS Code.  If you do have other projects that need CMake installed directly on Windows there is probably a setting for pointing to which version of CMake you would like the extension to use.  However, I didn't do that research and just use the MSYS2 environment (or WSL2) for my C/C++ development on Windows.  Keeps things simple.  A TODO would be to reasearch how to confugure the extension for which CMake instance you would like it to use, if possible at this time.

- Follow the tutorial at the following link up until the 'Create A Hello World App' section (You can continue with the tutorial if you like, but not neccessary)
    - [Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)
- To make this development environment a little more user friendly, I recommned reviewing the following: 
    - [CMake Tools Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
        - Extension for VS code providing a UI for using the tool.
    - [CppUTest Adapter Extension](https://marketplace.visualstudio.com/items?itemName=bneumann.cpputest-test-adapter)
        - Extension for VS code providing a UI for running unit tests.  A launch.json has also been provided for debugging unit tests from the UI.
- Install [git for windows](https://gitforwindows.org/)
- Install ninja, cmake, doxygen, and gcovr with the following commands 
    - pacman -S mingw-w64-ucrt-x86_64-ninja
    - pacman -S mingw-w64-ucrt-x86_64-cmake
    - pacman -S mingw-w64-ucrt-x86_64-python-pip
    - pacman -S mingw-w64-ucrt-x86_64-python-lxml
    - pip install gcovr
- Once all of that is done we can clone the unit testing frame works from the book.
    - Clone Unity [Unity GitHub](https://github.com/ThrowTheSwitch/Unity) to your desired location.
        - Create an environemnt var **UNITY_HOME** which points to root folder of repo.
        - switch to tag for v2.6.0
    - Clone CppUTest [CppUTest GitHub](https://github.com/cpputest/cpputest) to your desired location.
        - Create an environment var **CPPUTEST_HOME** which points to root folder of repo.
        - switch to tag for v4.0

- List of tools used and their versions
    - MSYS2,  20240113 
    - Ninja   1.11.1 
    - CMake   3.28.1 
    - Doxygen 1.10.0 
    - gcovr   7.2 

### Configure and Build with CMake

CMake is a two step process; 1) configure 2) then build.

The VS Code extension for CMake offers plenty of buttons through the UI to do this, or ctrl+shift+p can be used to bring up the command palette and then type cmake.  Select the command you want to use from the palette.

### Choosing which test framework to use with CMake

Choose the test framework to use through the setting **cmake.configureSettings** found in the .code-workspace file

```
"cmake.configureSettings":
{
    "USE_UNITY:BOOL":false,
    "USE_CPPUTEST:BOOL":false,
},
```
