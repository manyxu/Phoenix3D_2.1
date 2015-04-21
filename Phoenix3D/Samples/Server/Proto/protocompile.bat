@echo off

protoc -I=./ --cpp_out=./ ./account.proto 

pause