cmake_minimum_required(VERSION 3.12)
project(pb_battleroyale)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

find_package(SFML COMPONENTS graphics window system audio)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(source ${CMAKE_SOURCE_DIR}/src)

add_executable(pb_battleroyale
	${source}/handlers/mainhandler.cpp
	${source}/map/location.cpp
	${source}/app.cpp
	${source}/main.cpp
	${source}/helpers.cpp
	${source}/spdlog.cpp
	${source}/ini.c
	${source}/managers/texturemanager.cpp
	${source}/texturepacker.cpp
	${source}/managers/musicmanager.cpp
	${source}/map/mapmanager.cpp
	${source}/managers/obstaclemanager.cpp
)

add_definitions(-DSPDLOG_COMPILED_LIB)

target_link_libraries(pb_battleroyale sfml-graphics sfml-window sfml-system sfml-audio)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
target_link_libraries(pb_battleroyale pthread)
endif()