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
libitem_la_SOURCES = GameManager.cpp AudioHandler.cpp Button.cpp Character.cpp FadeHandler.cpp FadeScreen.cpp GameObject.cpp InputManager.cpp Map.cpp MainMenuButHandler.cpp Network.cpp SDLBase.cpp Scene.cpp SceneLegal.cpp SceneLogo.cpp SceneMainMenu.cpp ScenePhaseOne.cpp SceneTechnology.cpp SceneThirdParty.cpp Shape.cpp SplashScreen.cpp Sprite.cpp Tile.cpp 

# Libraries needed to build our library
libitem_la_LIBADD = -lSDL -lSDLmain -lSDL_image

# Program description
Ankhnowledge_SOURCES =	main.cpp
dist_Ankhnowledge_DATA = ../$(PACKAGE)/resources/images/adam.png ../$(PACKAGE)/resources/images/background.png ../$(PACKAGE)/resources/images/Black.bmp ../$(PACKAGE)/resources/images/block.png ../$(PACKAGE)/resources/images/splashlegal.png ../$(PACKAGE)/resources/images/splashlogo.png ../$(PACKAGE)/resources/images/splashmainmenu.png ../$(PACKAGE)/resources/images/splashtechnology.png ../$(PACKAGE)/resources/images/splashthirdparty.png ../$(PACKAGE)/resources/images/suti.png ../$(PACKAGE)/resources/images/tile.png ../$(PACKAGE)/resources/images/titlebg.png ../$(PACKAGE)/resources/images/connect_1.png ../$(PACKAGE)/resources/images/connect_2.png ../$(PACKAGE)/resources/images/connect_3.png ../$(PACKAGE)/resources/images/credits_1.png ../$(PACKAGE)/resources/images/credits_2.png ../$(PACKAGE)/resources/images/credits_3.png ../$(PACKAGE)/resources/images/host_1.png ../$(PACKAGE)/resources/images/host_2.png ../$(PACKAGE)/resources/images/host_3.png ../$(PACKAGE)/resources/images/options_1.png ../$(PACKAGE)/resources/images/options_2.png ../$(PACKAGE)/resources/images/options_3.png ../$(PACKAGE)/resources/images/quit_1.png ../$(PACKAGE)/resources/images/quit_2.png ../$(PACKAGE)/resources/images/quit_3.png
Ankhnowledgedir = /usr/local/$(PACKAGE)/resources/images

# Libraries needed to build program
Ankhnowledge_LDADD = libitem.la	

# Include flags
INCLUDES = -I../include -Wall -Wno-long-long

