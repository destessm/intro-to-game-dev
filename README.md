# intro-to-game-dev
Project Repo for CS 585: Intro to Game Development

## Build Instructions
Please use cmake by using these commands:

mkdir build  
cd build  
cmake ..  
make  
./runTests

## Notes
My explanation for my algorithm is in [DynamicArray](../master/src/engine/containers/dynamic_array.h "DynamicArray"). 

Currently the build is not working on Travis CI. It will work in linux running gcc-4.8, but Travis CI has ceased allowing for 4.8 support. I'm certain that there's a reason somewhere in my code that it isn't working (namely with the DynamicArray initializations in [DynamicArrayTests](../master/tests/dynamic_array_tests.cpp "DynamicArrayTests"). The compiler also does a little complaining about using "-std=c++11" or "-std=gnu11", which is why it needs gcc-4.8. 

I spent a lot of time working on this, but I clearly needed more time than I allowed. I want to get as much feedback as I can from this assignment so I can fix it and get working on the next. 

[Personal coding standard](../master/coding_standard.md "coding standard")
