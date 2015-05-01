@echo off

: dir
cd /d E:\GitHub\Phoenix3D\Phoenix3D\PX2ToLua
del "PX2ToLua.cpp"
: tolua
tolua++.exe -n PX2 -o PX2ToLua.cpp PX2ToLua.pkg

pause