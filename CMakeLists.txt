cmake_minimum_required(VERSION 3.7)
project(ExercisedExtendClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PlikSRT.cpp PlikSRT.h PlikTXT.cpp PlikTXT.h function.h function.cpp)
add_executable(ExercisedExtendClass ${SOURCE_FILES})