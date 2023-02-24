cmake_minimum_required(VERSION 3.24)
project(LearningCPlus)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCPlus main.cpp test/Add.h test/addFunction.cpp test/AddMain.cpp testArray/SumSource.cpp testPoint/TestPoint.cpp)
