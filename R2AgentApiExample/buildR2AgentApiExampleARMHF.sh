mkdir build 
cd build 
cmake ../ARMHF 
make 
print
cp apiexample ../../AgentStandalone/ARMHF/gcc-4.9.3/
cp apiexample ../../AgentStandalone/ARMHF/gcc-5.4/
cd .. 
rm -r build
