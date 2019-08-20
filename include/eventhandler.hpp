#pragma once

#include <SFML/Graphics.hpp>

class EventHandler {
public:
	void update() { };
	void draw() { };

	void event_quit(sf::RenderWindow* window) { window->close(); }
};