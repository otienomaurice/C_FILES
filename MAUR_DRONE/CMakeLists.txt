
#Define the CMake Version
cmake_minimum_required(VERSION 3.5)
#Define the project Name and Version
project(MAUR_DRONE VERSION  1.0)
#define the c standard 
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)
#set c compiler
set(CMAKE_C_COMPILER C:\Program Files\GCC\bin)
#add the executable 
#first define the target then the individual source files
add_executable(MAUR_DRONE gcc_open.c)

