cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++14)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} src)

add_executable(Tetris src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/tetris.cpp src/gameboard.cpp include/variable.h include/controller.h include/game.h include/gameboard.h include/renderer.h include/tetris.h include/variable.h)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Tetris ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
