cmake_minimum_required(VERSION 3.12)
project(pb_battleroyale)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -DSPDLOG_COMPILED_LIB")

include_directories(${CMAKE_SOURCE_DIR}/src)

set(framework sdl2)

set(source ${CMAKE_SOURCE_DIR}/src)

add_executable(pb_battleroyale
	${source}/main.cpp

	${source}/framework/${framework}/window.cpp

	${source}/handlers/mainhandler.cpp
	${source}/map/location.cpp
	${source}/app.cpp
	${source}/helpers.cpp
	${source}/spdlog.cpp
	${source}/ini.c
	${source}/managers/texturemanager.cpp
	${source}/texturepacker.cpp
	${source}/managers/musicmanager.cpp
	${source}/map/mapmanager.cpp
	${source}/managers/obstaclemanager.cpp
)

target_link_libraries(pb_battleroyale pthread sfml-graphics sfml-window sfml-system sfml-audio mingw32 SDL2main SDL2)
