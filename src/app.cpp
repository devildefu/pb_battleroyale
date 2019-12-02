#include <app.hpp>

/**
 * INI Handler
 */
static int handler(void* user, const char* section, const char* name, const char* value) {
	config* pconfig = (config*)user;

#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
	if(MATCH("options", "fps")) {
		pconfig->fps = atoi(value);
	} else if(MATCH("window", "width")) {
		pconfig->window_width = atoi(value);
	} else if(MATCH("window", "height")) {
		pconfig->window_height = atoi(value);
	} else {
		return 0;
	}
	return 1;
}

App::App()
	: window(new Window(1280, 720, "Perypetie Boba Battle Royale")) {
	//window->setView(sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(320, 180))));
	SPDLOG_INFO("Initializing game");

	SPDLOG_INFO("Parsing config file");

	config config;
	config.fps = 0;
	config.window_width = 0;
	config.window_height = 0;

	if(ini_parse("config.ini", handler, &config) < 0) {
		SPDLOG_WARN("Can't load config.ini");
	} else {
		SPDLOG_INFO("Config - fps: {}, window_width: {}, window_height: {}", config.fps, config.window_width, config.window_height);
	}

	if(config.fps > 0) {
		window->set_framerate_limit(config.fps);
	}

	if(config.window_width > 0 && config.window_height > 0) {
		//window->setSize(sf::Vector2u(config.window_width, config.window_height));
	} else {
		/*
		uint32_t width = sf::VideoMode::getDesktopMode().width;
		uint32_t height = sf::VideoMode::getDesktopMode().height;

		SPDLOG_INFO("DesktopMode: {}x{}", width, height);

		// Let's find the smallest number
		short ratio = std::min(width, height);

		// Should we divide by 320 or 180?
		if(ratio == width) {
			ratio /= 320;
		} else if(ratio == height) {
			ratio /= 180;
		}

		// ratio -= 1 will give too big a size (I think)
		if(ratio - 2 > 0)
			ratio -= 2;
		else
			ratio = 1;

		SPDLOG_INFO("The size of the window will be set to: {}x{}", ratio * 320, ratio * 180);

		window->setSize(sf::Vector2u(ratio * 320, ratio * 180));
		*/
	}

	SPDLOG_INFO("Parsing completed");

	// Check if the directory exists
	if(!Helpers::file_exists("assets/obstacles/")) {
		SPDLOG_ERROR("\"assets/obstacles/\" not found!");
		exit(1);
	}

	// Load all blocks to TextureManager and ObstacleManager
	int i = 0;
	ObstacleManager().add(Obstacle(0, false, false));
	for(const auto& entry : std::filesystem::directory_iterator("assets/obstacles/")) {
		i++;
		TextureManager().load_obstacle("assets/obstacles/" + std::to_string(i));
		ObstacleManager().add(Obstacle(i, false, false));
	}

	MusicManager().load("despacito", "despacito.wav");
	MusicManager().play("despacito");
	MusicManager().set_volume(1);
}

App::~App() {
	SPDLOG_INFO("Cleaning");

	for(auto handler : handlers) {
		delete handler.second;
	}
	handlers.clear();

	if(window)
		delete window;
}

int App::run() {
	while(window->is_open()) {
		handle_events();

		update();
		draw();
	}

	return 0;
}

void App::handle_events() {
	// TODO: Rework event system
	SDL_Event e;
	if(SDL_PollEvent(&e)) {
		switch(e.type) {
		case SDL_QUIT:
			SPDLOG_INFO("Received window close event");
			if(current_handler)
				current_handler->event_quit(window);
			else
				window->close();
			break;

		/*
		case sf::Event::Resized: {
			sf::View window_view = window->getView();
			float window_ratio = window->getSize().x / (float)window->getSize().y;
			float view_ratio = window_view.getSize().x / (float)window_view.getSize().y;

			float size_x = 1;
			float size_y = 1;
			float pos_x = 0;
			float pos_y = 0;

			bool horizontal_spacing = true;
			if(window_ratio < view_ratio) {
				horizontal_spacing = false;
			}

			if(horizontal_spacing) {
				size_x = view_ratio / window_ratio;
				pos_x = (1 - size_x) / 2.f;
			} else {
				size_y = window_ratio / view_ratio;
				pos_y = (1 - size_y) / 2.f;
			}

			window_view.setViewport(sf::FloatRect(pos_x, pos_y, size_x, size_y));
			window->setView(window_view);
		} break;
		*/

		default:
			break;
		}
	}
}

void App::update() {
	if(current_handler)
		current_handler->update(window);
}

void App::draw() {
	if(current_handler)
		current_handler->draw(window);
}
