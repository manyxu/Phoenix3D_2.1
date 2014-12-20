#!/bin/bash
# set params
NDK_ROOT_LOCAL=/cygdrive/d/android/android-ndk-r8e
PX2_ROOT_LOCAL=/cygdrive/e/repo/Phoenix3dp1
PX2_BIN_ROOT_LOCAL=/cygdrive/e/repo/Bin

# set roots
if [ $NDK_ROOT"xyz" != "xyz" ]; then
	echo "use global definition of NDK_ROOT: $NDK_ROOT"
	NDK_ROOT_LOCAL=$NDK_ROOT
fi

if [ $PX2_ROOT"xyz" != "xyz" ]; then
	echo "use global definition of PX2_ROOT: $PX2_ROOT"
	PX2_ROOT_LOCAL=$PX2_ROOT
fi

if [ $PX2_BIN_ROOT_LOCAL"xyz" != "xyz" ]; then
	echo "use global definition of PX2_BIN_ROOT_LOCAL: $PX2_BIN_ROOT_LOCAL"
	PX2_BIN_ROOT_LOCAL=$PX2_BIN_ROOT_LOCAL
fi

GAMEPLAY_ANDROID_ROOT=$PX2_ROOT_LOCAL/GamePlay/Proj.Android

# assets
if [ -d $GAMEPLAY_ANDROID_ROOT/assets ]; then
	rm -rf $GAMEPLAY_ANDROID_ROOT/assets
fi

mkdir $GAMEPLAY_ANDROID_ROOT/assets
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/defines
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/effects
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/engine
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/fonts
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/images
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/language
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/models
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/mtls
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/musics
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/net
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/objects
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/projects
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/scenes
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/scripts
mkdir $GAMEPLAY_ANDROID_ROOT/assets/Data/sounds

# boost.lua boost.xml
cp -rf $PX2_BIN_ROOT_LOCAL/Data/boost.lua $GAMEPLAY_ANDROID_ROOT/assets/Data
cp -rf $PX2_BIN_ROOT_LOCAL/Data/boost.xml $GAMEPLAY_ANDROID_ROOT/assets/Data

#defines
for file in $PX2_BIN_ROOT_LOCAL/Data/defines/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/defines
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/defines
fi
done

#effects
for file in $PX2_BIN_ROOT_LOCAL/Data/effects/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/effects
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/effects
fi
done

# engine
for file in $PX2_BIN_ROOT_LOCAL/Data/engine/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/engine
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/engine
fi
done

# fonts
for file in $PX2_BIN_ROOT_LOCAL/Data/fonts/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/fonts
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/fonts
fi
done

# images
for file in $PX2_BIN_ROOT_LOCAL/Data/images/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/images
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/images
fi
done

# language
for file in $PX2_BIN_ROOT_LOCAL/Data/language/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/language
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/language
fi
done

#models
for file in $PX2_BIN_ROOT_LOCAL/Data/models/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/models
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/models
fi
done

# mtls
# do not need copy

# musics
# not copy this time

# net
for file in $PX2_BIN_ROOT_LOCAL/Data/net/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/net
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/net
fi
done

# objects
for file in $PX2_BIN_ROOT_LOCAL/Data/objects/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/objects
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/objects
fi
done

# projects
for file in $PX2_BIN_ROOT_LOCAL/Data/projects/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/projects
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/projects
fi
done

# scenes
for file in $PX2_BIN_ROOT_LOCAL/Data/scenes/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/scenes
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/scenes
fi
done

# scripts
for file in $PX2_BIN_ROOT_LOCAL/Data/scripts/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/scripts
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/scripts
fi
done

# sounds
for file in $PX2_BIN_ROOT_LOCAL/Data/sounds/*
do
if [ -d $file ]; then
cp -rf $file $GAMEPLAY_ANDROID_ROOT/assets/Data/sounds
fi
if [ -f $file ]; then
cp $file $GAMEPLAY_ANDROID_ROOT/assets/Data/sounds
fi
done

# copy resources

# build
echo "start build"

export NDK_MODULE_PATH=$PX2_ROOT_LOCAL\
:$PX2_ROOT_LOCAL/PX2Core/\
:$PX2_ROOT_LOCAL/PX2Mathematics/\
:$PX2_ROOT_LOCAL/PX2Graphics/\
:$PX2_ROOT_LOCAL/PX2EventSystem/\
:$PX2_ROOT_LOCAL/PX2Input/\
:$PX2_ROOT_LOCAL/PX2Unity/\
:$PX2_ROOT_LOCAL/PX2Terrains/\
:$PX2_ROOT_LOCAL/PX2Effect/\
:$PX2_ROOT_LOCAL/PX2UserInterface/\
:$PX2_ROOT_LOCAL/PX2Game/\
:$PX2_ROOT_LOCAL/MBMZ/\
:$PX2_ROOT_LOCAL/PX2AppFrame/\
:$PX2_ROOT_LOCAL/GamePlay/\
:$GAMEPLAY_ANDROID_ROOT

$NDK_ROOT_LOCAL/ndk-build -C $GAMEPLAY_ANDROID_ROOT

echo "end build"