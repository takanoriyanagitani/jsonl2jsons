cmake_minimum_required(VERSION 3.10)

project(jsonl2jsons VERSION 0.0.1)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g -coverage")
SET(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(jsonl2jsons_append_len_test jsonl2jsons_append_len_test.c)
add_executable(jsonl2jsons_append_test     jsonl2jsons_append_test.c)

enable_testing()

add_test(NAME jsonl2jsons_append_len_T1 COMMAND jsonl2jsons_append_len_test)
add_test(NAME jsonl2jsons_append_len_T2 COMMAND jsonl2jsons_append_len_test 0 0 1)
add_test(NAME jsonl2jsons_append_len_T3 COMMAND jsonl2jsons_append_len_test 3 0 4)
add_test(NAME jsonl2jsons_append_len_T4 COMMAND jsonl2jsons_append_len_test 3 1 5)
add_test(NAME jsonl2jsons_append_len_T5 COMMAND jsonl2jsons_append_len_test 3 4 8)

add_test(NAME jsonl2jsons_append_T1 COMMAND jsonl2jsons_append_test)
add_test(NAME jsonl2jsons_append_T2 COMMAND jsonl2jsons_append_test {}\n 16384 1 [{},)
add_test(NAME jsonl2jsons_append_T3 COMMAND jsonl2jsons_append_test {"h":634}\n 16384 1 [{"h":634},)
