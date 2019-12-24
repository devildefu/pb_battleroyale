#include <map/mapmanager.hpp>

bool MapManager::init() {
	if(!Helpers::file_exists(LOCATION_PATH)) {
		SPDLOG_ERROR("\"{}\" not found!", LOCATION_PATH);
		return true;
	}

	for(const auto& entry : fs::directory_iterator(LOCATION_PATH)) {
		std::string path = entry.path().string();
		std::string filename = entry.path().filename().string();

		SPDLOG_INFO("Loading location: {}", filename);

		// Remove extension from filename
		filename = filename.substr(0, filename.size() - strlen(LOCATION_EXT));

		int pos_x;
		int pos_y;

		// Get pos_x and pos_y from filename
		if(sscanf(filename.c_str(), "%i,%i", &pos_x, &pos_y) <= 0) {
			SPDLOG_ERROR("Failed to parse filename!");
			return true;
		}

		// TODO: Edit pb map format to support background info
		load_location(pos_x, pos_y, path, TextureManager().get(LOCATION_DEFAULT_BACKGROUND));
	}

	return false;
}

void MapManager::update(sf::RenderWindow* window) {
	
}

void MapManager::render(sf::RenderWindow* window) {
	// TODO: Make that the rendering was similar to PB

	uint32_t id = location_y * MAXIMUM_LOCATIONS + location_x;
	Location* current_location = locations[id];

	if(!current_location) {
		SPDLOG_ERROR("There's no location on the location array, x: {}, y: {}!", location_x, location_y);
		return;
	}

	window->draw(*current_location);
}

bool MapManager::load_location(int x, int y, const std::string& path, sf::Texture& background) {
	if(path.empty()) {
		SPDLOG_ERROR("Location path is empty");
		return true;
	}

	uint32_t id = LOC_POS(x, y);

	if(locations[id]) {
		SPDLOG_WARN("Trying to override Location object! x: {}, y: {}", x, y);
	} else {
		SPDLOG_INFO("Adding location to array... x: {}, y: {}", x, y);
	}

	locations[id] = new Location(background, TextureManager().get_obstacles(), path.c_str());
	return false;
}

void MapManager::add_location_to_array(int x, int y, Location* location) {
	if(!location) {
		SPDLOG_ERROR("location is undefined! Aborting.");
		return;
	}

	uint32_t id = LOC_POS(x, y);

	if(locations[id]) {
		SPDLOG_WARN("Trying to override Location object! x: {}, y: {}", x, y);
	} else {
		SPDLOG_INFO("Adding location to array... x: {}, y: {}", x, y);
	}

	locations[id] = location;
}