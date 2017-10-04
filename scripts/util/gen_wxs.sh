#!/bin/bash
#
# Generates .exe installer for Windows
#

# Include project metadata
. metadata.ini

COMMON_PATH="dist/windows/$PACKAGE_NAME.wxs"
OUTPUT_FILE=$EXECUTABLE_NAME.exe
PACKAGE_VERSION=$VERSION_MAJOR.$VERSION_MINOR.$VERSION_RELEASE

function get_uuid(){
	UUID=`uuidgen`
	UUID=${UUID^^}
	echo $UUID
}

COMPONENT_IDS="MainExecutable "

function create_directory_file() {
	cat > "$COMMON_PATH.directory" <<EOF
		<Directory Id='TARGETDIR' Name='SourceDir'>
			<Directory Id='ProgramFilesFolder' Name='PFiles'>
				<Directory Id='UnBGames' Name='UnB Games'>
					<Directory Id='INSTALLDIR' Name="$PACKAGE_NAME $PACKAGE_VERSION">
						<Component Id='MainExecutable' Guid="`get_uuid`">
							<File
								Id="$PACKAGE_NAME"
								Name="$OUTPUT_FILE"
								DiskId='1'
								Vital='yes'
								Source="$OUTPUT_FILE"
								KeyPath='yes'>
							</File>
						</Component>
EOF
}

function append_file_tag() {
	WXS_COMPONENT=$1
	FILE_NAME=$2
	ID=${2//\//_}
	ID=${ID//-/_}
	ID=${ID//+/_}
	cat >> $WXS_COMPONENT <<EOF
	<File
		Id="_${ID^^}"
		Name="${FILE_NAME##*/}"
		DiskId='1'
		Source="$FILE_NAME"/>
EOF
}

function append_icon_tag() {
	WXS_COMPONENT=$1
	cat >> $WXS_COMPONENT <<EOF
	<Icon Id="icon.ico" SourceFile="resources/icon.ico" />
EOF
}


function append_component_tag() {
	WXS_COMPONENT=$1
	FILE_NAME=$2
	ID="_${FILE_NAME^^}"
	COMPONENT_IDS+="$ID "
	cat >> $WXS_COMPONENT <<EOF
	<Component Id="$ID" Guid="`get_uuid`" KeyPath='yes'>
EOF
}

function append_directory_tag() {
	WXS_COMPONENT=$1
	DIR_NAME=$2
	cat >> $WXS_COMPONENT <<EOF
	<Directory Id="${DIR_NAME^^}DIR" Name="$DIR_NAME">
EOF
}

function close_tag() {
	WXS_COMPONENT=$1
	TAG=$2
	cat >> $WXS_COMPONENT <<EOF
	</${TAG}>
EOF
}

function gen_header() {
	cat > "$COMMON_PATH.header" <<EOF
<?xml version='1.0' encoding='windows-1252'?>
<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>
	<Product
		Name="$PACKAGE_NAME $PACKAGE_VERSION"
		Id="`get_uuid`"
		UpgradeCode="`get_uuid`"
		Language='1046'
		Codepage='1252'
		Version="$PACKAGE_VERSION"
		Manufacturer='UnB Games'>
	<Package
		Id='*'
		Keywords='Installer'
		Description="$PACKAGE_NAME $PACKAGE_VERSION installer"
		Manufacturer='UnB Games'
		InstallerVersion='100'
		Languages='1046'
		SummaryCodepage='1252'
		Compressed='yes'/>

		<Media
			Id='1'
			Cabinet='$PACKAGE_NAME.cab'
			EmbedCab='yes'
			DiskPrompt="Disk #1"
		/>

		<Property
			Id='DiskPrompt'
			Value="$PACKAGE_NAME $PACKAGE_VERSION Installation [1]"
		/>
EOF
}

function append_componentRef_tag() {
	WXS_COMPONENT=$1
	ID=$2
	cat >> $WXS_COMPONENT <<EOF
	<ComponentRef Id="$ID" />
EOF
}

function append_feature_tag() {
	WXS_COMPONENT=$1
	ID=$2
	cat >> $WXS_COMPONENT <<EOF
	<Feature Id="$ID" Level='1' >
EOF
}

function gen_feature() {
	WXS_DIR="$COMMON_PATH.directory"
	append_feature_tag $WXS_DIR "Complete"
	for COMP_ID in $COMPONENT_IDS;
	do
		append_componentRef_tag $WXS_DIR $COMP_ID
	done
	close_tag $WXS_DIR "Feature"

	close_tag $WXS_DIR "Product"
	close_tag $WXS_DIR "Wix"
}

function check_directory_for_file() {
	WXS_DIR="$COMMON_PATH.directory"
	BASE_DIR=$1

	for FILE in $(ls $BASE_DIR);
	do
		FILE_PATH="$BASE_DIR/$FILE"
		if [ -d FILE_PATH ];
		then
			append_directory_tag $WXS_DIR $FILE
			check_directory_for_file $FILE_PATH
			close_tag $WXS_DIR "Directory"
		fi
		append_component_tag $WXS_DIR $FILE
		append_file_tag $WXS_DIR $FILE_PATH
		close_tag $WXS_DIR "Component"
	done;
}

function gen_directory()
{
	WXS_DIR="$COMMON_PATH.directory"
	create_directory_file

	append_component_tag $WXS_DIR "SDL"
	for DLL in $(ls bin/windows/ -I *.exe);
	do
		append_file_tag $WXS_DIR $DLL
	done
	close_tag $WXS_DIR "Component"

	append_directory_tag $WXS_DIR "resources"
	check_directory_for_file "resources"
	close_tag $WXS_DIR "Directory"

	close_tag $WXS_DIR "Directory"
	close_tag $WXS_DIR "Directory"
	close_tag $WXS_DIR "Directory"
	close_tag $WXS_DIR "Directory"

	## Add manual!
	# append_icon_tag $WXS_DIR

}

if ! [ -e "$COMMON_PATH.header" ];
then
	gen_header
fi

if ! [ -e "$COMMON_PATH.directory" ];
then
	gen_directory
	gen_feature
fi


mkdir -p .tmp
cp -u src/$EXECUTABLE_NAME\_release .tmp/$OUTPUT_FILE
cp -u bin/windows/* .tmp/
cp -f "$COMMON_PATH.header" .tmp/$PACKAGE_NAME.wxs
cat "$COMMON_PATH.directory" >> .tmp/$PACKAGE_NAME.wxs
cat "$COMMON_PATH.feature" >> .tmp/$PACKAGE_NAME.wxs

# cp -u dist/windows/Manual.pdf .tmp/
cp -ur resources .tmp/

cd .tmp

candle.exe $PACKAGE_NAME.wxs
light.exe -sice:ICE60 -ext WixUIExtension $PACKAGE_NAME.wixobj
cp $PACKAGE_NAME.msi ..
cd ..
