: dir
cd /d E:\GitHub\Phoenix3D\Phoenix3D\PX2ToLua
del "PX2ToLuaEditor.cpp"
: tolua
tolua++.exe -n PX2Editor -o PX2ToLuaEditor.cpp PX2ToLuaEditor.pkg