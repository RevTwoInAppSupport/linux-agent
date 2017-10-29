#!/bin/bash
mkdir build 
cd build 
cmake ../Desktop 
make 
cp apiexample ../../../R2AgentStandalone/Desktop/gcc-4.8.5/
cp apiexample ../../../R2AgentStandalone/Desktop/gcc-5.4/
cd .. 
rm -r build
echo "Goto ../../R2AgentStandalone/Desktop/{your_gcc_version}, and try apiexample!"
