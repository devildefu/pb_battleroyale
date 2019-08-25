cmake_minimum_required(VERSION 3.12)
project(pb_battleroyale)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSPDLOG_COMPILED_LIB")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(source ${CMAKE_SOURCE_DIR}/src)

file(GLOB files
	${source}/*.cpp
	${source}/handlers/*.cpp
	${source}/map/*.cpp
)

add_executable(pb_battleroyale ${files})
target_link_libraries(pb_battleroyale pthread sfml-graphics sfml-window sfml-system)