cmake_minimum_required(VERSION 3.12)
project(pb_battleroyale)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSPDLOG_COMPILED_LIB")

include_directories(${CMAKE_SOURCE_DIR}/src)

set(source ${CMAKE_SOURCE_DIR}/src)

add_executable(pb_battleroyale
	${source}/handlers/mainhandler.cpp
	${source}/map/location.cpp
	${source}/app.cpp
	${source}/main.cpp
	${source}/spdlog.cpp
	${source}/ini.c
	${source}/texturemanager.cpp
	${source}/texturepacker.cpp
	${source}/map/mapmanager.cpp
)

target_link_libraries(pb_battleroyale pthread sfml-graphics sfml-window sfml-system)
