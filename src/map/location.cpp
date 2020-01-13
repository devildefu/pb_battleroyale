#include <cstring>
#include <managers/texturemanager.hpp>
#include <map/location.hpp>

Location::Location(Location& loc)
	: bg(loc.bg)
	, tileset(loc.tileset) {
	init();
}

Location::Location(sf::Texture& background, sf::Texture& tileset)
	: bg(background)
	, tileset(tileset) {
	init();
}

Location::Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size)
	: bg(background)
	, tileset(tileset) {
	init();

	create_from_array(map, size);
}

Location::Location(sf::Texture& background, sf::Texture& tileset, const char* fname)
	: bg(background)
	, tileset(tileset) {
	init();

	load(fname);
}

Obstacle* Location::get_obstacle(int x, int y) {
	uint16_t id = this->id[y * LOCATION_WIDTH + x];
	return ObstacleManager().get(id);
}

uint16_t Location::get_obstacle_id(int x, int y) {
	return id[y * LOCATION_WIDTH + x];
}

void Location::create_from_array(uint16_t map[], int size) {
	int8_t pos_x = -1; // 0 % 18 will return 0, so we need to set to -1
	int8_t pos_y = 0;

	for(int i = 0; i < size; i++) {
		// Should we increase pos_y?
		if(i % 18 == 0) {
			pos_x++;
			pos_y = 0;
		} else {
			pos_y++;
		}

		int id = map[i];
		set_obstacle(pos_x, pos_y, id);
	}
}

void Location::set_obstacle(int x, int y, Obstacle* current_obstacle) {
	if(current_obstacle == nullptr) return;

	if(x >= LOCATION_WIDTH || x < 0) {
		SPDLOG_ERROR("Position x is too small or too large!");
		return;
	} else if(y >= LOCATION_HEIGHT || y < 0) {
		SPDLOG_ERROR("Position y is too small or too large!");
		return;
	}

	uint16_t id = current_obstacle->get_id();
	sf::Vertex* quad = &vertices[(y * LOCATION_WIDTH + x) * 4];

	if(id > 0) {
		// Calculation of the position
		quad[0].position = sf::Vector2f(x * OBSTACLE_SCALE, y * OBSTACLE_SCALE);
		quad[1].position = sf::Vector2f((x + 1) * OBSTACLE_SCALE, y * OBSTACLE_SCALE);
		quad[2].position = sf::Vector2f((x + 1) * OBSTACLE_SCALE, (y + 1) * OBSTACLE_SCALE);
		quad[3].position = sf::Vector2f(x * OBSTACLE_SCALE, (y + 1) * OBSTACLE_SCALE);

		sf::IntRect rect = current_obstacle->get_rect();

		// Calculation of the texture position
		quad[0].texCoords = sf::Vector2f(rect.left, rect.top);
		quad[1].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
		quad[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
		quad[3].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
	} else {
		quad[0].position = sf::Vector2f(-1, -1);
		quad[1].position = sf::Vector2f(-1, -1);
		quad[2].position = sf::Vector2f(-1, -1);
		quad[3].position = sf::Vector2f(-1, -1);

		quad[0].texCoords = sf::Vector2f(-1, -1);
		quad[1].texCoords = sf::Vector2f(-1, -1);
		quad[2].texCoords = sf::Vector2f(-1, -1);
		quad[3].texCoords = sf::Vector2f(-1, -1);
	}

	this->id[y * LOCATION_WIDTH + x] = id;
}

void Location::set_obstacle(int x, int y, uint16_t id) {
	if(x >= LOCATION_WIDTH || x < 0) {
		SPDLOG_ERROR("Position x is too small or too large!");
		return;
	} else if(y >= LOCATION_HEIGHT || y < 0) {
		SPDLOG_ERROR("Position y is too small or too large!");
		return;
	}

	sf::Vertex* quad = &vertices[(y * LOCATION_WIDTH + x) * 4];

	if(id > 0) {
		// Calculation of the position
		quad[0].position = sf::Vector2f(x * OBSTACLE_SCALE, y * OBSTACLE_SCALE);
		quad[1].position = sf::Vector2f((x + 1) * OBSTACLE_SCALE, y * OBSTACLE_SCALE);
		quad[2].position = sf::Vector2f((x + 1) * OBSTACLE_SCALE, (y + 1) * OBSTACLE_SCALE);
		quad[3].position = sf::Vector2f(x * OBSTACLE_SCALE, (y + 1) * OBSTACLE_SCALE);

		sf::IntRect rect = ObstacleManager().get(id)->get_rect();

		// Calculation of the texture position
		quad[0].texCoords = sf::Vector2f(rect.left, rect.top);
		quad[1].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
		quad[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
		quad[3].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
	} else {
		quad[0].position = sf::Vector2f(-1, -1);
		quad[1].position = sf::Vector2f(-1, -1);
		quad[2].position = sf::Vector2f(-1, -1);
		quad[3].position = sf::Vector2f(-1, -1);

		quad[0].texCoords = sf::Vector2f(-1, -1);
		quad[1].texCoords = sf::Vector2f(-1, -1);
		quad[2].texCoords = sf::Vector2f(-1, -1);
		quad[3].texCoords = sf::Vector2f(-1, -1);
	}
	this->id[y * LOCATION_WIDTH + x] = id;
}

void Location::save(const char* fname, uint16_t* map, int size) {
	FILE* f = fopen(fname, "wb");
	// Failed to create a file
	if(f == NULL) return;

	fwrite(map, sizeof(uint16_t), size, f);
	fclose(f);
}

void Location::load(const char* fname) {
	FILE* f = fopen(fname, "rb");
	// Failed to create a file
	if(f == NULL) return;

	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);

	uint16_t* map = (uint16_t*)malloc(size);
	size /= sizeof(uint16_t);
	fread(map, sizeof(uint16_t), size, f);
	fclose(f);

	create_from_array(map, size);
}
