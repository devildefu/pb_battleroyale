#pragma once

#include <spdlog/spdlog.h>
#include <vector>

#include <framework/window.hpp>

#include <eventhandler.hpp>
#include <map/mapmanager.hpp>
#include <object.hpp>
#include <managers/texturemanager.hpp>
#include <managers/obstaclemanager.hpp>
#include <helpers.hpp>

class MainHandler : public EventHandler {
public:
	virtual void update(Window* window);
	virtual void draw(Window* window);
	virtual void init();
	virtual void clear();

private:
	std::vector<Object*> objects;
	MapManager map;
};