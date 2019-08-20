#pragma once

#include <SFML/Graphics.hpp>

class EventHandler {
public:
	/**
	 * Called upon each logic update to the game.
	 */
	void update() { };

	/**
	 * Called to do the drawing of your game.
	 */
	void draw() { };

	/**
	 * Called when current handler will be changed to another
	 */
	void clear() { };

	/**
	 * Called when current handler is changed
	 */
	void init() { };

	/**
	 * Called when window is closed
	 */
	void event_quit(sf::RenderWindow* window) { window->close(); }
};