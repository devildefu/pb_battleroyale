#pragma once

#include <string>

#include <SDL2/SDL.h>

class Window {
public:
	Window(int width, int height, const std::string& title);
	~Window();

	void set_framerate_limit(int limit) { fps = limit; }

	bool is_open() { return !quit; }
	void close() { quit = true; }
	
	void clear() { }
	void display() { }
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* render = nullptr;
	uint16_t fps = 0;
	bool quit = false;
};