# !/bin/bash
# Author: João Pedro Sconetto - sconetto.joao@gmail.com
# Date: 22/05/2017

DOCS="./doc-pak/"
SRC="./src/"
INC="./include/"

sudo apt install libtool autoconf automake libsdl-image1.2 libsdl-image1.2-dev libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl-mixer1.2 libsdl-mixer1.2-dev libsdl-net1.2 libsdl-net1.2-dev -y

sleep 2

mv $DOCS/* .
./cleanup.sh
./bootstrap.sh
./configure

sleep 2

sudo make install

sudo mv AUTHORS ChangeLog COPYING description-pak INSTALL NEWS README $DOCS

sleep 1
