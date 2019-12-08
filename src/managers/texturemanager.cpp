#include <invalidtexture.hpp>
#include <managers/texturemanager.hpp>

impl::TextureManager::TextureManager() {
	SPDLOG_INFO("Initialized TextureManager");
	obstacle_packer = new TexturePacker(obstacles);

	// TODO: Rewrite this. We load TWO TIME textures (once in app.cpp, once here), which slows down the time of loading.
	int i = 0;
	int size_x = 0;
	int size_y = 0;

	for(const auto& entry : std::filesystem::directory_iterator("assets/obstacles/")) {
		i++;
		sf::Texture tex;
		tex.loadFromFile("assets/obstacles/" + std::to_string(i) + ".png");

		size_x += tex.getSize().x;
		if(size_y < tex.getSize().y) {
			size_y = tex.getSize().y;
		}
	}

	// TODO: Resizing when needed
	SPDLOG_INFO("{} {}", size_x, size_y);
	obstacles.create(size_x, size_y);
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

		// Try to load texture
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

		// Try to load texture
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

sf::IntRect impl::TextureManager::load_obstacle(std::string texture) {
	SPDLOG_INFO("Loading obstacle \"{}\"", texture);

	sf::Texture txt;
	if(!txt.loadFromFile(texture + ".png")) {
		// Failed to load
		SPDLOG_ERROR("Cannot load {} texture file", texture + ".png");
		txt.loadFromMemory(invalidtexture, size_invalidtexture);
	}

	// Pack
	return obstacle_packer->pack(txt);;
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