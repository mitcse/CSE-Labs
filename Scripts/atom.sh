#!/bin/bash

wget 'https://github.com/atom/atom/releases/download/v1.9.9/atom-amd64.tar.gz'
tar -xzvf atom-amd64.tar.gz
mkdir ~/.atom
mv atom-1.9.9-amd64/* ~/.atom
echo "alias atom='~/.atom/atom'" >> ~/.bashrc
rm atom-amd64.tar.gz
rmdir atom-1.9.9-amd64/
echo "------------------------------------"
echo "Use 'atom' for exegguting atom. Open a new terminal, this will close now."
sleep 2

# Copy the following line (Uncommented) and paste it in the terminal to install atom in one go

# $(wget 'https://raw.githubusercontent.com/mitcse/CSE-Labs/master/Scripts/atom.sh') sh atom.sh && rm atom.sh && exit