cmake_minimum_required(VERSION 3.5)
project(iawar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
		src/defs.h++
		src/opt.c++
		src/opt.h++
		src/ropts.c++
		src/ropts.h++
		src/main.c++)
add_executable(iawar ${SOURCE_FILES})