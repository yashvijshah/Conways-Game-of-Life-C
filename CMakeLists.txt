cmake_minimum_required(VERSION 2.8)
project(YOUR_PROJECT_NAME)

set (CMAKE_BUILD_TYPE Debug)

set (CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(unity/include)

add_executable(gameoflife main.c game.c file.c view.c)
add_executable(unit_tests unit_tests.c game.c file.c view.c unity/src/unity.c)

target_link_libraries(gameoflife ${SDL2_LIBRARIES})
target_link_libraries(unit_tests ${SDL2_LIBRARIES})
