@echo off

:: 转到目录
E:
cd E:/GitHub/Phoenix3D/Bin/build_android

:: so编译
call _build_so.bat

::apk打包
E:
cd E:/GitHub/Phoenix3D/Bin/build_android
call _build_ant.bat

pause