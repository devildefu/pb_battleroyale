#include <cstring>
#include <map/location.hpp>
#include <managers/texturemanager.hpp>

const int SCALE = 10;

Location::Location() {
}

Location::Location(sf::Texture& background, sf::Texture& tileset)
	: background(background)
	, tileset(tileset) {
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(LOCATION_WIDTH * LOCATION_HEIGHT * 4);
}

Location::Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size)
	: background(background)
	, tileset(tileset) {
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(LOCATION_WIDTH * LOCATION_HEIGHT * 4);

	create_from_array(map, size);
}

Location::Location(sf::Texture& background, sf::Texture& tileset, const char* fname)
	: background(background)
	, tileset(tileset) {
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(LOCATION_WIDTH * LOCATION_HEIGHT * 4);

	load(fname);
}

void Location::create_from_array(uint16_t map[], int size) {
	int8_t pos_x = -1; // 0 % 18 == 0, so we need to set to -1
	int8_t pos_y = 0;

	for(int i = 0; i < size; i++) {
		// Should we increase pos_x?
		if(i % 18 == 0) {
			pos_x++;
			pos_y = 0;
		} else {
			pos_y++;
		}

		int id = map[i];
		if(id > 0) set_obstacle(pos_x, pos_y, ObstacleManager().get(id));
	}
}

void Location::set_obstacle(int x, int y, Obstacle* obstacle) {
	if(obstacle == nullptr) return;

	sf::Vertex* quad = &vertices[(y * LOCATION_WIDTH + x) * 4];
	// Calculation of the position
	quad[0].position = sf::Vector2f(x * SCALE, y * SCALE);
	quad[1].position = sf::Vector2f((x + 1) * SCALE, y * SCALE);
	quad[2].position = sf::Vector2f((x + 1) * SCALE, (y + 1) * SCALE);
	quad[3].position = sf::Vector2f(x * SCALE, (y + 1) * SCALE);

	int id = obstacle->get_id();
	sf::IntRect rect = obstacle->get_rect();	

	// Calculation of the texture position
	quad[0].texCoords = sf::Vector2f(rect.left, rect.top);
	quad[1].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
	quad[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
	quad[3].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
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
