cmake_minimum_required(VERSION 3.21)
project(remote_test)

set(CMAKE_CXX_STANDARD 11)

add_executable(remote_test Book.cpp Book.h main.cpp Studen.cpp Student.h User.cpp User.h Teacher.cpp Teacher.h)