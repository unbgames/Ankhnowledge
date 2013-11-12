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
libitem_la_SOURCES = Animation.cpp GameManager.cpp AudioHandler.cpp Button.cpp Block.cpp BlockMovable.cpp BlockWater.cpp BlockTreasure.cpp Character.cpp CreditsController.cpp FadeHandler.cpp FadeScreen.cpp GameObject.cpp InputManager.cpp Map.cpp MainMenuButHandler.cpp Network.cpp OptionsController.cpp SDLBase.cpp Scene.cpp SceneLegal.cpp SceneLogo.cpp SceneMainMenu.cpp ScenePhaseOne.cpp SceneTechnology.cpp SceneThirdParty.cpp SceneGameOver.cpp SceneCredits.cpp SceneOptions.cpp Shape.cpp SplashScreen.cpp Sprite.cpp Slider.cpp Skill.cpp SkillDig.cpp Tile.cpp BlockSand.cpp SkillSand.cpp


# Libraries needed to build our library
libitem_la_LIBADD = -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lSDL_mixer

# Program description
Ankhnowledge_SOURCES =	main.cpp
dist_Ankhnowledge_DATA = ../$(PACKAGE)/resources/images/intro.ogg ../$(PACKAGE)/resources/images/sand_action.wav ../$(PACKAGE)/resources/images/dig_action.wav ../$(PACKAGE)/resources/images/main_menu.ogg ../$(PACKAGE)/resources/images/adam.png ../$(PACKAGE)/resources/images/background.png ../$(PACKAGE)/resources/images/Black.bmp ../$(PACKAGE)/resources/images/block.png ../$(PACKAGE)/resources/images/splashlegal.png ../$(PACKAGE)/resources/images/splashlogo.png ../$(PACKAGE)/resources/images/splashmainmenu.png ../$(PACKAGE)/resources/images/splashtechnology.png ../$(PACKAGE)/resources/images/splashthirdparty.png ../$(PACKAGE)/resources/images/suti.png ../$(PACKAGE)/resources/images/tile.png ../$(PACKAGE)/resources/images/titlebg.png ../$(PACKAGE)/resources/images/connect_1.png ../$(PACKAGE)/resources/images/connect_2.png ../$(PACKAGE)/resources/images/connect_3.png ../$(PACKAGE)/resources/images/credits_1.png ../$(PACKAGE)/resources/images/credits_2.png ../$(PACKAGE)/resources/images/credits_3.png ../$(PACKAGE)/resources/images/host_1.png ../$(PACKAGE)/resources/images/host_2.png ../$(PACKAGE)/resources/images/host_3.png ../$(PACKAGE)/resources/images/options_1.png ../$(PACKAGE)/resources/images/options_2.png ../$(PACKAGE)/resources/images/options_3.png ../$(PACKAGE)/resources/images/quit_1.png ../$(PACKAGE)/resources/images/quit_2.png ../$(PACKAGE)/resources/images/quit_3.png ../$(PACKAGE)/resources/images/adam_spr.png ../$(PACKAGE)/resources/images/suti_spr.png ../$(PACKAGE)/resources/images/slider_button.png ../$(PACKAGE)/resources/images/slider_bar.png ../$(PACKAGE)/resources/images/credits.png ../$(PACKAGE)/resources/images/back_1.png ../$(PACKAGE)/resources/images/back_2.png ../$(PACKAGE)/resources/images/back_3.png ../$(PACKAGE)/resources/images/options.png ../$(PACKAGE)/resources/images/lost.png ../$(PACKAGE)/resources/images/box.png ../$(PACKAGE)/resources/images/box_input.png ../$(PACKAGE)/resources/images/cursor.png ../$(PACKAGE)/resources/images/interface.png ../$(PACKAGE)/resources/images/quicksandbold.ttf ../$(PACKAGE)/resources/images/ok_1.png ../$(PACKAGE)/resources/images/ok_2.png ../$(PACKAGE)/resources/images/ok_3.png ../$(PACKAGE)/resources/images/Bau.png ../$(PACKAGE)/resources/images/Tilecomareia.png ../$(PACKAGE)/resources/images/bauanimacao.png ../$(PACKAGE)/resources/images/areiamovedicabloco.png ../$(PACKAGE)/resources/images/areiamovedica.png ../$(PACKAGE)/resources/images/alanhud.png ../$(PACKAGE)/resources/images/sutihud.png ../$(PACKAGE)/resources/images/endturn_1.png ../$(PACKAGE)/resources/images/endturn_2.png ../$(PACKAGE)/resources/images/endturn_3.png 
Ankhnowledgedir = /usr/local/$(PACKAGE)/resources/images

# Libraries needed to build program
Ankhnowledge_LDADD = libitem.la	

# Include flags
INCLUDES = -I../include -Wall -Wno-long-long

