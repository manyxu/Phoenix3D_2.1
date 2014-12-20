: dir
cd /d E:/mgame/Phoenix3d/PX2ToLua
del "PX2ToLua.cpp"
: tolua
tolua++.exe -n PX2 -o PX2ToLua.cpp PX2ToLua.pkg