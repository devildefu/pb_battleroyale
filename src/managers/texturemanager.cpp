#include <invalidtexture.hpp>
#include <managers/texturemanager.hpp>

impl::TextureManager::TextureManager() {
	SPDLOG_INFO("Initialized TextureManager");
	obstacle_packer = new TexturePacker(obstacles);

	obstacle_rects.push_back(sf::IntRect(-1, -1, -1, -1));

	int i = 0;
	sf::Vector2i size;

	std::vector<sf::Texture*> textures;

	for(const auto& entry : std::filesystem::directory_iterator(OBSTACLE_PATH)) {
		std::string path = entry.path().string();

		sf::Texture* tex = new sf::Texture;
		tex->loadFromFile(path);

		size.x += tex->getSize().x;
		if(size.y < tex->getSize().y) {
			size.y = tex->getSize().y;
		}
		textures.push_back(tex);
	}

	obstacles.create(size.x, size.y);

	for(auto texture : textures) {
		load_from_memory(texture, "", TextureType::Obstacle);
	}
}

impl::TextureManager::~TextureManager() {
	SPDLOG_INFO("Cleaning textures");
	clear();

	delete obstacle_packer;
}

sf::Texture& impl::TextureManager::get(std::string name) {
	if(!exists(name)) {
		SPDLOG_INFO("Loading texture {}", name);
		load(name, TextureType::Normal);
	}

	SPDLOG_INFO("Requested texture {}", name);
	return *this->textures[name];
}

bool impl::TextureManager::load(std::string name, TextureType type) {
	bool status = true;
	if(!exists(name)) {
		sf::Texture* texture = new sf::Texture;

		if(!texture->loadFromFile(name + ".png")) {
			SPDLOG_ERROR("Cannot load {} texture file", name + ".png");
			texture->loadFromMemory(invalidtexture, size_invalidtexture);

			// "Invalid texture" loaded instead
			status = false;
		}

		load_from_memory(texture, name, type);
	}

	return status;
}

void impl::TextureManager::load_from_memory(sf::Texture* texture, std::string name, TextureType type) {
	switch(type) {
	case TextureType::Normal:
		this->textures[name] = texture;
		break;

	case TextureType::Obstacle:
		sf::IntRect& rect = obstacle_packer->pack(*texture);
		obstacle_rects.push_back(rect);
		break;
	}
}

bool impl::TextureManager::remove(std::string texture) {
	if(!exists(texture)) {
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
	return !(this->textures.find(texture) == this->textures.end());
}