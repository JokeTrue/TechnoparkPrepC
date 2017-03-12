cmake_minimum_required(VERSION 3.6)
project(Challenge_2)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES list.h list.c)
add_library(objlib OBJECT ${SOURCE_FILES})
add_library(GenericList_shared SHARED ${SOURCE_FILES})
add_library(GenericList_static STATIC ${SOURCE_FILES})
SET_TARGET_PROPERTIES(GenericList_static PROPERTIES OUTPUT_NAME GenericList_static CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(GenericList_shared PROPERTIES OUTPUT_NAME GenericList_shared CLEAN_DIRECT_OUTPUT 1)