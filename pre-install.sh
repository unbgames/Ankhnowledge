# !/bin/bash
# Author: João Pedro Sconetto - sconetto.joao@gmail.com
# Date: 24/04/2017

sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libsdli* -y
sudo apt-get install libtool automake autoconf -y
sudo apt-get install freeglut3 libglew1.1* glew-utils -y

/bin/bash cleanup.sh
/bin/bash bootstrap.sh
/bin/bash configure
