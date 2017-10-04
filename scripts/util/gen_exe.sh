
# if ! [ -e "$COMMON_PATH.directory" ];
# then
# 	gen_directory
# fi

# if ! [ -e "$COMMON_PATH.feature"];
#!/bin/bash
#
# Generates .exe installer for Windows
#

# Include project metadata
. metadata.ini

COMMON_PATH="dist/windows/$PACKAGE_NAME.wxs"
OUTPUT_FILE=$EXECUTABLE_NAME.exe
PACKAGE_VERSION=$VERSION_MAJOR.$VERSION_MINOR.$VERSION_RELEASE

####### PASSOS PARA GERAR O WXS:
## 1. Encontrar a pasta recursos (fazer executavel pra encontrar a pasta?)
## 2. Listar recursos (recursivamente)
## 3. Montar parte do arquivo, com os recursos (sendo um componente pra cada)
## 4. Juntar arquivos

scripts/util/gen_wxs.sh

# function gen_exe()
# {
# 	mkdir -p .tmp
# 	cp -u src/$EXECUTABLE_NAME\_release .tmp/$OUTPUT_FILE
# 	cp -u lib/SDL/windows/release/*.dll .tmp/
# 	cp -u lib/SDL_image/windows/release/*.dll .tmp/
# 	cp -u lib/SDL_image/windows/release/LICENSE* .tmp/
# 	cp -f dist/windows/template-test.wxs .tmp/$PACKAGE_NAME.wxs
# 	cp -u dist/windows/Manual.pdf .tmp/
# 	cp -ur resources .tmp/

# 	cd .tmp
#     sed -i -- 's/%%OUTPUT_FILE%%/'"$OUTPUT_FILE"'/g' $PACKAGE_NAME.wxs
#     sed -i -- 's/%%PACKAGE_NAME%%/'"$PACKAGE_NAME"'/g' $PACKAGE_NAME.wxs
#     sed -i -- 's/%%PACKAGE_VERSION%%/'"$PACKAGE_VERSION"'/g' $PACKAGE_NAME.wxs
#     sed -i -- 's/%%MAINTAINER_NAME%%/'"$MAINTAINER_NAME"'/g' $PACKAGE_NAME.wxs
#     sed -i -- 's/%%GAME_DESCRIPTION%%/'"$GAME_DESCRIPTION"'/g' $PACKAGE_NAME.wxs

# 	candle.exe $PACKAGE_NAME.wxs
# 	light.exe -sice:ICE60 -ext WixUIExtension $PACKAGE_NAME.wixobj
# 	cp $PACKAGE_NAME.msi ..
# 	cd ..
# }

# echo "Generating "$OUTPUT_FILE "..."
# gen_exe
# echo "Done"
