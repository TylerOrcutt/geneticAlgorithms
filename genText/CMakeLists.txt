cmake_minimum_required(VERSION 3.6)
project( genText) # this is case sensitive
 SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
 find_package(PkgConfig REQUIRED)
 

 
add_executable(${PROJECT_NAME} main.cpp  )
 
