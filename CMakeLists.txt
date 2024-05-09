cmake_minimum_required(VERSION 3.27)
project(coom1222_ATMProgram)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(coom1222_ATMProgram
        Account.h
        ATMachine.h
        main.cpp
        ATMachine.cpp
        Account.cpp)
