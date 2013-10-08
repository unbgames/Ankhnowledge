# Author: Edson Alves - edsonalves@unb.br
# Date: 26/11/2010

# Library description
lib_LTLIBRARIES = libitem.la

# Programs excluded from instalation
#noinst_PROGRAMS = main
bin_PROGRAMS = Ankhnowledge

# Library flags
libitem_la_LDFLAGS = -static

# Library sources
libitem_la_SOURCES = GameManager.cpp AudioHandler.cpp Character.cpp FadeHandler.cpp FadeScreen.cpp GameObject.cpp InputManager.cpp Network.cpp SDLBase.cpp Shape.cpp Sprite.cpp TileMap.cpp TileSet.cpp

# Libraries needed to build our library
libitem_la_LIBADD = -lSDL -lSDLmain -lSDL_image

# Program description
Ankhnowledge_SOURCES =	main.cpp
dist_Ankhnowledge_DATA = ../$(PACKAGE)/resources/images/charac.png ../$(PACKAGE)/resources/images/background.png ../$(PACKAGE)/resources/images/Black.bmp
Ankhnowledgedir = /usr/local/$(PACKAGE)/resources/images

# Libraries needed to build program
Ankhnowledge_LDADD = libitem.la	

# Include flags
INCLUDES = -I../include -Wall -Wno-long-long

