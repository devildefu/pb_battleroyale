#include <invalidtexture.hpp>
#include <managers/texturemanager.hpp>

impl::TextureManager::TextureManager() {
	SPDLOG_INFO("Initialized TextureManager");
	obstacle_packer = new TexturePacker(obstacles);

	obstacle_rects.push_back(sf::IntRect(0, 0, 0, 0));

	int i = 0;
	int size_x = 0;
	int size_y = 0;

	std::vector<sf::Texture> textures;

	for(const auto& entry : std::filesystem::directory_iterator(OBSTACLE_PATH)) {
		i++;
		sf::Texture tex;
		tex.loadFromFile(OBSTACLE_PATH + std::to_string(i) + ".png");

		size_x += tex.getSize().x;
		if(size_y < tex.getSize().y) {
			size_y = tex.getSize().y;
		}
		textures.push_back(tex);
	}

	SPDLOG_INFO("{} {}", size_x, size_y);
	obstacles.create(size_x, size_y);

	for(int i = 1; i <= textures.size(); i++) {
		load(OBSTACLE_PATH + std::to_string(i), TextureType::Obstacle);
	}
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

sf::IntRect& impl::TextureManager::get_obstacle_rect(uint16_t id) {
	return obstacle_rects[id];
}

bool impl::TextureManager::load(std::string texture, TextureType type) {
	if(this->textures.find(texture) == this->textures.end()) {
		sf::Texture* txt = new sf::Texture();

		if(!txt->loadFromFile(texture + ".png")) {
			SPDLOG_ERROR("Cannot load {} texture file", texture + ".png");
			txt->loadFromMemory(invalidtexture, size_invalidtexture);
			return false;
		}

		switch(type) {
			case TextureType::Normal: 
				this->textures[texture] = txt;
				break;

			case TextureType::Obstacle:
				sf::IntRect& rect = obstacle_packer->pack(*txt);
				obstacle_rects.push_back(rect);
				break;
		}
		return true;
	} else {
		return true;
	}
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
	return !(this->textures.find(texture) == this->textures.end());
}