#pragma once

#include <spdlog/spdlog.h>

#include <eventhandler.hpp>
#include <vector>
#include <object.hpp>

class MainHandler : public EventHandler {
public:
	virtual void update(sf::RenderWindow* window);
	virtual void draw(sf::RenderWindow* window);
	virtual void init();
	virtual void clear();

protected:
	std::vector<Object*> objects;
};