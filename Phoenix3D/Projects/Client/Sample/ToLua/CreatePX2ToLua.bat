@echo off

: dir
cd /d C:\Users\xuduo\Documents\GitHub\Phoenix3D\Phoenix3D\Samples\Client\Soccer\ToLua
del "PX2ToLuaSoccer.cpp"
: tolua
tolua++.exe -n PX2Soccer -o PX2ToLuaSoccer.cpp PX2ToLuaSoccer.pkg

pause