cmake_minimum_required(VERSION 2.8.9)
project (gmock-example)
 
#For the static library:
set ( PROJECT_LINK_LIBS libgtest.a libgmock.a libgmock_main.a libgtest_main.a )
link_directories( /usr/lib )

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pthread")
 
add_executable(gmock-example-test main.cpp)
target_link_libraries(gmock-example-test ${PROJECT_LINK_LIBS} )

message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")




