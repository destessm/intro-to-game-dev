cmake_minimum_required(VERSION 2.8)
project( main )

# Set up support for c++11
SET(CMAKE_CXX_FLAGS "-std=c++11")

# Set up Google Test
enable_testing()
find_package( Threads )
add_subdirectory( gtest-1.7.0 )
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

# Add Executables
add_executable( main game.m.cpp )
add_executable( runTests tests/main_tests.cpp )
include_directories( src/engine/containers )
include_directories( src/engine/memory )

# Link libraries
target_link_libraries( runTests gtest gtest_main )
target_link_libraries( runTests ${CMAKE_THREAD_LIBS_INIT} )

# Add Tests
add_test( NAME runTests COMMAND runTests )
