#pragma once

#include <SFML/Graphics.hpp>

class EventHandler {
public:
	/**
	 * Called upon each logic update to the game.
	 */
	virtual void update(sf::RenderWindow* window) {};

	/**
	 * Called to do the drawing of your game.
	 */
	virtual void draw(sf::RenderWindow* window) {};

	/**
	 * Called when current handler will be changed to another
	 */
	virtual void clear() {};

	/**
	 * Called when current handler is changed
	 */
	virtual void init(sf::RenderWindow* window) {};

	/**
	 * Called when window is closed
	 */
	virtual void event_quit(sf::RenderWindow* window) { window->close(); }

	virtual void event_mouse_wheel_scrolled(sf::RenderWindow* window, sf::Event::MouseWheelScrollEvent data) {};
	virtual void event_mouse_button_pressed(sf::RenderWindow* window, sf::Event::MouseButtonEvent data) {};
	virtual void event_mouse_button_released(sf::RenderWindow* window, sf::Event::MouseButtonEvent data) {};
	virtual void event_mouse_move(sf::RenderWindow* window, sf::Event::MouseMoveEvent data) {};

	virtual void before_event(sf::RenderWindow* window, sf::Event& event) {};
};