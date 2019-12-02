#include "../window.hpp"

Window::Window(int width, int height, const std::string& title) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Perypetie Boba Battle Royale", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window() {
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);

	render = nullptr;
	window = nullptr;

	SDL_Quit();
}