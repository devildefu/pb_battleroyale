#pragma once

#include <SFML/Graphics.hpp>

class EventHandler {
public:
	void update() { };
	void draw() { };
	
	void clear() { };
	void init() { };

	void event_quit(sf::RenderWindow* window) { window->close(); }
};