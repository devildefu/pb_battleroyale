#pragma once

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include <vector>
#include <algorithm>

#include <eventhandler.hpp>
#include <map/mapmanager.hpp>
#include <object.hpp>
#include <managers/texturemanager.hpp>
#include <managers/obstaclemanager.hpp>
#include <helpers.hpp>

class MainHandler : public EventHandler {
public:
	virtual void update(sf::RenderWindow* window);
	virtual void draw(sf::RenderWindow* window);
	virtual void init(sf::RenderWindow* window);
	virtual void clear();

private:
	std::vector<Object*> objects;
	MapManager map;
};