#include <invalidtexture.hpp>
#include <managers/texturemanager.hpp>

impl::TextureManager::TextureManager() {
	SPDLOG_INFO("Initialized TextureManager");
	obstacle_packer = new TexturePacker(obstacles);

	// TODO: Resizing when needed
	obstacles.create(1024, 1024);
}

impl::TextureManager::~TextureManager() {
	SPDLOG_INFO("Cleaning textures");
	for(auto&& [key, val] : this->textures) {
		delete val;
	}

	delete obstacle_packer;
}

sf::Texture& impl::TextureManager::get(std::string texture) {
	SPDLOG_INFO("Requested texture \"{}\"", texture);
	if(this->textures.find(texture) == this->textures.end()) {
		sf::Texture* txt = new sf::Texture();

		if(!txt->loadFromFile(texture + ".png")) {
			SPDLOG_ERROR("Cannot load {} texture file", texture + ".png");
			txt->loadFromMemory(invalidtexture, size_invalidtexture);
		}

		this->textures[texture] = txt;
		return *txt;
	} else {
		return *this->textures[texture];
	}
}

bool impl::TextureManager::load(std::string texture) {
	SPDLOG_INFO("Loading texture \"{}\"", texture);
	if(this->textures.find(texture) == this->textures.end()) {
		sf::Texture* txt = new sf::Texture();

		if(!txt->loadFromFile(texture + ".png")) {
			SPDLOG_ERROR("Cannot load {} texture file", texture + ".png");
			txt->loadFromMemory(invalidtexture, size_invalidtexture);
			return false;
		}

		this->textures[texture] = txt;
		return true;
	} else {
		return true;
	}
}

bool impl::TextureManager::load_obstacle(std::string texture) {
	SPDLOG_INFO("Loading obstacle \"{}\"", texture);

	sf::Texture txt;
	if(!txt.loadFromFile(texture + ".png")) {
		// Failed to load
		SPDLOG_ERROR("Cannot load {} texture file", texture + ".png");
		txt.loadFromMemory(invalidtexture, size_invalidtexture);
		return false;
	}

	// Pack
	obstacle_packer->pack(txt);
	return true;
}

bool impl::TextureManager::remove(std::string texture) {
	if(this->textures.find(texture) == this->textures.end()) {
		return false;
	} else {
		delete this->textures[texture];
		this->textures.erase(texture);
		return true;
	}
}

void impl::TextureManager::clear() {
	for(auto&& [key, val] : this->textures) {
		delete val;
	}
}

bool impl::TextureManager::exists(std::string texture) {
	if(this->textures.find(texture) == this->textures.end()) {
		return false;
	} else {
		return true;
	}
}