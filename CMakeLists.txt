cmake_minimum_required(VERSION 2.8)
project( main )

# Set up Google Test
enable_testing()
find_package( Threads )
# include_directories( $ENV{GTEST_ROOT}/include )
# link_directories( $ENV{GTEST_ROOT}/build )
add_subdirectory( gtest-1.7.0 )
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

# Add Executables
add_executable( main game.m.cpp )
add_executable( runUnitTests unit_tests.cpp )

# Link libraries
target_link_libraries( runUnitTests gtest gtest_main )
target_link_libraries( runUnitTests ${CMAKE_THREAD_LIBS_INIT} )

# Add Tests
add_test( NAME runUnitTests COMMAND runUnitTests )
