
cmake_minimum_required(VERSION 4.2)

project(complexite)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c)

add_executable(exec ${SOURCES})
