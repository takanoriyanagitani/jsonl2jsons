cmake_minimum_required(VERSION 3.10)

project(jsonl2jsons VERSION 0.0.1)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g -coverage")
SET(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(jsonl2jsons_init_test        jsonl2jsons_init_test.c)
add_executable(jsonl2jsons_append_len_test  jsonl2jsons_append_len_test.c)
add_executable(jsonl2jsons_append_test      jsonl2jsons_append_test.c)
add_executable(jsonl2jsons_append_rows_test jsonl2jsons_append_rows_test.c)

enable_testing()

add_test(NAME jsonl2jsons_init_T1 COMMAND jsonl2jsons_init_test)
add_test(NAME jsonl2jsons_init_T2 COMMAND jsonl2jsons_init_test "0" "-1")
add_test(NAME jsonl2jsons_init_T3 COMMAND jsonl2jsons_init_test "1" "-1")
add_test(NAME jsonl2jsons_init_T4 COMMAND jsonl2jsons_init_test "2" "-1")
add_test(NAME jsonl2jsons_init_T5 COMMAND jsonl2jsons_init_test "3" "0")
add_test(NAME jsonl2jsons_init_T6 COMMAND jsonl2jsons_init_test "4" "0")
add_test(NAME jsonl2jsons_init_T7 COMMAND jsonl2jsons_init_test "5" "0")

add_test(NAME jsonl2jsons_append_len_T1 COMMAND jsonl2jsons_append_len_test)
add_test(NAME jsonl2jsons_append_len_T2 COMMAND jsonl2jsons_append_len_test 0 0 1)
add_test(NAME jsonl2jsons_append_len_T3 COMMAND jsonl2jsons_append_len_test 3 0 4)
add_test(NAME jsonl2jsons_append_len_T4 COMMAND jsonl2jsons_append_len_test 3 1 5)
add_test(NAME jsonl2jsons_append_len_T5 COMMAND jsonl2jsons_append_len_test 3 4 8)

add_test(NAME jsonl2jsons_append_T1 COMMAND jsonl2jsons_append_test)
add_test(NAME jsonl2jsons_append_T2 COMMAND jsonl2jsons_append_test {}\n 16384 1 [{}, 0)
add_test(NAME jsonl2jsons_append_T3 COMMAND jsonl2jsons_append_test {"h":634}\n 16384 1 [{"h":634}, 0)
add_test(NAME jsonl2jsons_append_T4 COMMAND jsonl2jsons_append_test {"s":634}\n {"t":333}\n [{"s":634},{"t":333}] 0)
add_test(NAME jsonl2jsons_append_T5 COMMAND jsonl2jsons_append_test {}\n 0 1 empty, -1)
add_test(NAME jsonl2jsons_append_T6 COMMAND jsonl2jsons_append_test {}\n 1 1 empty, -1)
add_test(NAME jsonl2jsons_append_T7 COMMAND jsonl2jsons_append_test {}\n 2 1 empty, -1)
add_test(NAME jsonl2jsons_append_T8 COMMAND jsonl2jsons_append_test {}\n 3 1 empty, -1)
add_test(NAME jsonl2jsons_append_T9 COMMAND jsonl2jsons_append_test {}\n 4 1 empty, -1)
add_test(NAME jsonl2jsons_append_Ta COMMAND jsonl2jsons_append_test {}\n 5 1 [{}, 0)

add_test(NAME jsonl2jsons_append_rows_T1 COMMAND jsonl2jsons_append_rows_test)
add_test(NAME jsonl2jsons_append_rows_T2 COMMAND jsonl2jsons_append_rows_test i1.jsonl e1.json 70)
add_test(NAME jsonl2jsons_append_rows_T3 COMMAND jsonl2jsons_append_rows_test i2.jsonl e2.json 70)
