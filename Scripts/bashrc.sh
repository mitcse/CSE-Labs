#!/bin/bash

# Useful aliases and functions for bash.
# Copy paste these into the ~/.bashrc

alias ..='cd ..'            # Go back 1 directory level
alias ...='cd ../../'       # Go back 2 directory levels
alias ....='cd ../../../'   # Go back 3 directory levels

alias docs='cd ~/Documents'

alias open='nautilus'	# nautilus opens the specific folder with the file manager on Ubuntu
alias f='nautilus .'	# Open the current folder

alias c='clear'			# Clear screen

# ls
alias lsa='ls -alh'

# Give exeggutable permissions to a file
alias exc='chmod a+x'

# quick open .bashrc
alias editbash='gedit ~/.bashrc'

# shortcut for compiling and exegguting Java programs
# usage javax helloworld.java
function javax {
    filename="${1%.*}"
    javac $filename.java
    if [[ $? == 0 ]]; then
       java $filename
    fi
}

# shortcut for compiling and exegguting Java applets
# usage javaw helloapplet.java
function javaw {
    filename="${1%.*}"
    javac $filename.java
    if [[ $? == 0 ]]; then
       appletviewer $filename.java
    fi
}

# shortcut for compiling and exegguting C programs
# usage cx helloworld.c
function cx {
    filename="${1%.*}"
    gcc $filename.c -o $filename.o
    if [[ $? == 0 ]]; then
       ./$filename.o
    fi
}

# shortcut for compiling and exegguting C++ programs
# usage cpx helloworld.cpp
function cpx {
    filename="${1%.*}"
    g++ $filename.cpp -o $filename.o
    if [[ $? == 0 ]]; then
       ./$filename.o
    fi
}