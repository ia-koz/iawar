cmake_minimum_required(VERSION 3.5)
project(iawar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES
        src/defs.h++
        src/opt.h++
        src/opt.c++
        src/ropts.h++
        src/ropts.c++
        src/point.h++
        src/point.c++
        src/unit.h++
        src/unit.c++
        src/ground.h++
        src/ground.c++
        src/air.h++
        src/air.c++
        src/squad.h++
        src/squad.c++
        src/main.c++)
add_executable(iawar ${SOURCE_FILES})