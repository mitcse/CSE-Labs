#!/bin/bash

wget 'https://download.sublimetext.com/sublime_text_3_build_3114_x64.tar.bz2'
mv 'sublime_text_3_build_3114_x64.tar.bz2' 'sublime.tar.bz2'
tar jxf sublime.tar.bz2
mkdir ~/.sublime
mv sublime_text_3/* ~/.sublime
echo "alias subl='~/.sublime/sublime_text'" >> ~/.bashrc
rm sublime.tar.bz2
rmdir sublime_text_3/
echo "------------------------------------"
echo "Use 'subl' for sublime text. Open a new terminal, this will close now."
sleep 2

# Copy the following line (Uncommented) and paste it in the terminal to install sublime_text_3 in one go

# $(wget 'https://raw.githubusercontent.com/mitcse/CSE-Labs/master/Scripts/sublime.sh') sh sublime.sh && rm sublime.sh && exit