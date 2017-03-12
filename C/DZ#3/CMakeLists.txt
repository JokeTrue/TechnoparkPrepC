cmake_minimum_required(VERSION 3.6)
project(C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES "main.c" "words.c" "words.h" "../Challenge#2/list.c" "../Challenge#2/list.h")
add_executable(C ${SOURCE_FILES})