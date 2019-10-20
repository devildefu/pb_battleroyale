#include <invalidtexture.hpp>
#include <managers/texturemanager.hpp>

impl::TextureManager::~TextureManager() {
	SPDLOG_INFO("Cleaning textures");
	for(auto&& [key, val] : this->textures) {
		delete val;
	}
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