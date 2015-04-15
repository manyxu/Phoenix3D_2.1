# build.sh

# set params
NDK_ROOT_LOCAL=/cygdrive/d/adt-bundle-windows/ndk
ENGINE_ROOT_LOCAL=/cygdrive/e/GitHub/Phoenix3D/Phoenix3D
APPPLAY_MYAPP_BIN_ROOT_LOCAL=/cygdrive/e/GitHub/Phoenix3D/Bin
APPPLAY_MYAPP_DATAFROM=Data

if [ $NDK_ROOT"xyz" != "xyz" ]; then
	echo "use global definition of NDK_ROOT: $NDK_ROOT"
	NDK_ROOT_LOCAL=$NDK_ROOT
fi

if [ $PX2_ROOT"xyz" != "xyz" ]; then
	echo "use global definition of PX2_ROOT: $PX2_ROOT"
	ENGINE_ROOT_LOCAL=$PX2_ROOT
fi

if [ $APPPLAY_MYAPP_BIN_ROOT_LOCAL"xyz" != "xyz" ]; then
	echo "use global definition of APPPLAY_MYAPP_BIN_ROOT_LOCAL: $APPPLAY_MYAPP_BIN_ROOT_LOCAL"
	APPPLAY_MYAPP_BIN_ROOT_LOCAL=$APPPLAY_MYAPP_BIN_ROOT_LOCAL
fi

APPPLAY_MYAPP_ANDROID_ROOT=$ENGINE_ROOT_LOCAL/PX2AppPlayer/Proj.Android

#clear and make dir
if [ -d $APPPLAY_MYAPP_ANDROID_ROOT/assets ]; then
	rm -rf $APPPLAY_MYAPP_ANDROID_ROOT/assets
fi
mkdir $APPPLAY_MYAPP_ANDROID_ROOT/assets
mkdir $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data
mkdir $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/engine
mkdir $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/engine_mtls
mkdir $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/sample_phoenix3d

# copy resources

# boost.lua boost.xml version.xml versionList.dat
cp -rf $APPPLAY_MYAPP_BIN_ROOT_LOCAL/$APPPLAY_MYAPP_DATAFROM/boost.xml $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data
cp -rf $APPPLAY_MYAPP_BIN_ROOT_LOCAL/$APPPLAY_MYAPP_DATAFROM/version.xml $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data
cp -rf $APPPLAY_MYAPP_BIN_ROOT_LOCAL/$APPPLAY_MYAPP_DATAFROM/versionList.dat $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data

# engine
for file in $APPPLAY_MYAPP_BIN_ROOT_LOCAL/$APPPLAY_MYAPP_DATAFROM/engine/*
do
if [ -d $file ]; then
cp -rf $file $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/engine
fi
if [ -f $file ]; then
cp $file $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/engine
fi
done

# engine_mtls
for file in $APPPLAY_MYAPP_BIN_ROOT_LOCAL/$APPPLAY_MYAPP_DATAFROM/engine_mtls/*
do
if [ -d $file ]; then
cp -rf $file $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/engine_mtls
fi
if [ -f $file ]; then
cp $file $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/engine_mtls
fi
done

# projects
for file in $APPPLAY_MYAPP_BIN_ROOT_LOCAL/$APPPLAY_MYAPP_DATAFROM/sample_phoenix3d/*
do
if [ -d $file ]; then
cp -rf $file $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/sample_phoenix3d
fi
if [ -f $file ]; then
cp $file $APPPLAY_MYAPP_ANDROID_ROOT/assets/Data/sample_phoenix3d
fi
done

chmod -R 777 $APPPLAY_MYAPP_ANDROID_ROOT/assets

# build
echo "start build"

export NDK_MODULE_PATH=$ENGINE_ROOT_LOCAL\
:$ENGINE_ROOT_LOCAL/PX2Core/\
:$ENGINE_ROOT_LOCAL/PX2Mathematics/\
:$ENGINE_ROOT_LOCAL/PX2Graphics/\
:$ENGINE_ROOT_LOCAL/PX2Unity/\
:$ENGINE_ROOT_LOCAL/PX2Net/\
:$ENGINE_ROOT_LOCAL/PX2Effect/\
:$ENGINE_ROOT_LOCAL/PX2Terrains/\
:$ENGINE_ROOT_LOCAL/PX2UI/\
:$ENGINE_ROOT_LOCAL/PX2Simulation/\
:$ENGINE_ROOT_LOCAL/PX2AppFrame/\
:$ENGINE_ROOT_LOCAL/PX2AppPlayer/\
:$APPPLAY_MYAPP_ANDROID_ROOT

$NDK_ROOT_LOCAL/ndk-build -C $APPPLAY_MYAPP_ANDROID_ROOT

echo "end build"