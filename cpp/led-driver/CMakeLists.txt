cmake_minimum_required(VERSION 2.8.9)
project (led-driver-test)
 
#For the static library:
set ( PROJECT_LINK_LIBS libgtest.a libgmock.a libgmock_main.a libgtest_main.a )
link_directories( /usr/lib )

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pthread")

#Bring the headers
include_directories(include)

#if multiple files
file(GLOB SOURCES "src/*.cpp")
add_executable(led-driver-test ${SOURCES})

target_link_libraries(led-driver-test ${PROJECT_LINK_LIBS} )

message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")

#if only one main.cpp file 
#add_executable(led-driver-test main.cpp)
