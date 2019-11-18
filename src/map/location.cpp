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
	vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);
}

Location::Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size)
	: background(background)
	, tileset(tileset) {
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);

	create_from_array(map, size);
}

Location::Location(sf::Texture& background, sf::Texture& tileset, const char* fname)
	: background(background)
	, tileset(tileset) {
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);

	load(fname);
}

void Location::create_from_array(uint16_t map[], int size) {	
	for(int i = 0; i < size; i++) {
		int id = map[i];
		if(id > 0) set_obstacle(i, 0, ObstacleManager().get(id-1));
	}
}

void Location::set_obstacle(int x, int y, Obstacle* obstacle) {
	if(obstacle == nullptr) return;

	sf::Vertex* quad = &vertices[(y * MAP_WIDTH + x) * 4];
	// Calculation of the position
	quad[0].position = sf::Vector2f(x * SCALE, y * SCALE);
	quad[1].position = sf::Vector2f((x + 1) * SCALE, y * SCALE);
	quad[2].position = sf::Vector2f((x + 1) * SCALE, (y + 1) * SCALE);
	quad[3].position = sf::Vector2f(x * SCALE, (y + 1) * SCALE);

	int id = obstacle->get_id();

	// TODO: Texture's Y detection
	// Calculation of the texture position
	quad[0].texCoords = sf::Vector2f(id * SCALE, 0 * SCALE);
	quad[1].texCoords = sf::Vector2f((id + 1) * SCALE, 0 * SCALE);
	quad[2].texCoords = sf::Vector2f((id + 1) * SCALE, (0 + 1) * SCALE);
	quad[3].texCoords = sf::Vector2f(id * SCALE, (0 + 1) * SCALE);
}

void Location::save(const char* fname, uint16_t* map, int size) {
	FILE* f = fopen(fname, "wb");
	if(f == NULL) return;

	fwrite(map, sizeof(uint16_t), size, f);
	fclose(f);
}

void Location::load(const char* fname) {
	FILE* f = fopen(fname, "rb");
	if(f == NULL) return;

	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);

	uint16_t* map = (uint16_t*)malloc(size);
	size /= sizeof(uint16_t);
	fread(map, sizeof(uint16_t), size, f);
	fclose(f);

	for(int i = 0; i < size; i++) {
		int id = map[i];
		if(id > 0) set_obstacle(i, 0, ObstacleManager().get(id-1));
	}
}
