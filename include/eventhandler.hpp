#pragma once

#include <SFML/Graphics.hpp>

class EventHandler {
public:
	/**
	 * Called upon each logic update to the game.
	 */
	virtual void update(sf::RenderWindow* window) { };

	/**
	 * Called to do the drawing of your game.
	 */
	virtual void draw(sf::RenderWindow* window) { };

	/**
	 * Called when current handler will be changed to another
	 */
	virtual void clear() { };

	/**
	 * Called when current handler is changed
	 */
	virtual void init() { };

	/**
	 * Called when window is closed
	 */
	virtual void event_quit(sf::RenderWindow* window) { window->close(); }
};