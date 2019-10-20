#pragma once

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include <eventhandler.hpp>
#include <map/mapmanager.hpp>
#include <object.hpp>
#include <texturemanager.hpp>
#include <vector>

class MainHandler : public EventHandler {
public:
	virtual void update(sf::RenderWindow* window);
	virtual void draw(sf::RenderWindow* window);
	virtual void init();
	virtual void clear();

private:
	std::vector<Object*> objects;
	MapManager map;
};