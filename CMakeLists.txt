cmake_minimum_required(VERSION 3.10)

project(jsonl2jsons VERSION 0.0.1)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g -coverage")
SET(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(jsonl2jsons jsonl2jsons.c)

enable_testing()

add_test(NAME Run COMMAND jsonl2jsons)
