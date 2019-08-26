#pragma once

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include <eventhandler.hpp>
#include <vector>
#include <object.hpp>
#include <map/mapmanager.hpp>
#include <texturemanager.hpp>

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