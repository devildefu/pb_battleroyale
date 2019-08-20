cmake_minimum_required(VERSION 3.12)
project(pb_battleroyale)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(source ${CMAKE_SOURCE_DIR}/src)
add_executable(pb_battleroyale 
${source}/main.cpp
${source}/app.cpp)
target_link_libraries(pb_battleroyale sfml-graphics sfml-window sfml-system)