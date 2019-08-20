#pragma once

#include <spdlog/spdlog.h>

#include <eventhandler.hpp>

class MainHandler : public EventHandler {
public:
	virtual void update(sf::RenderWindow* window) { }
	virtual void draw(sf::RenderWindow* window);
	virtual void init() { SPDLOG_INFO("aaa"); }
	virtual void clear() {}
};