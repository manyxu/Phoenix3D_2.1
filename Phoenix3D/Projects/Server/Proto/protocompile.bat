@echo off

protoc -I=./ --cpp_out=./ ./account.proto 
protoc -I=./ --cpp_out=./ ./db.proto 

pause