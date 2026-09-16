
cmake_minimum_required(VERSION 4.2)

project(sorting-algorithms C)

# lazy but it works
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c)

add_executable(exec ${SOURCES})
