# add by bingyu.song  for TinyNet 


cmake_minimum_required(VERSION 2.6)

project( TinyNet  CXX )


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS " -g -Wall -Werror -std=c++0x ")

set(CMAKE_CXX_FLAGS_DEBUG "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")



#ADD_DEFINITIONS(-D_DEBUG_)
ADD_DEFINITIONS(-D_TINY_OP_)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib)

ADD_SUBDIRECTORY(exam)
ADD_SUBDIRECTORY(exam/pingpong)
ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(tem)




