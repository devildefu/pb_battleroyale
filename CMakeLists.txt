cmake_minimum_required(VERSION 3.12)
project(pb_battleroyale)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSPDLOG_COMPILED_LIB")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(source ${CMAKE_SOURCE_DIR}/src)
add_executable(pb_battleroyale 
${source}/main.cpp
${source}/app.cpp
${source}/spdlog.cpp)
target_link_libraries(pb_battleroyale sfml-graphics sfml-window sfml-system)