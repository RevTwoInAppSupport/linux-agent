#!/bin/bash
mkdir build 
cd build 
cmake ../ARMHF 
make 
cp apiexample ../../../R2AgentStandalone/ARMHF/gcc-4.9.3/
cp apiexample ../../../R2AgentStandalone/ARMHF/gcc-5.4/
cd .. 
rm -r build
echo "Goto ../../R2AgentStandalone/ARMHF/{your_gcc_version}, and try apiexample!" 