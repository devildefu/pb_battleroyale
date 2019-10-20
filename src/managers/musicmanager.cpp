#include <managers/musicmanager.hpp>

impl::MusicManager::~MusicManager() {
	SPDLOG_INFO("Cleaning music");

	// Clean up
	for(auto&& [key, val] : this->musics) {
		delete val;
	}
}

void impl::MusicManager::load(const std::string& name, const std::string& filename) {
	SPDLOG_INFO("Loading new music, name: {}", name);

	/* Is music loaded? */
	if(this->musics.find(name) == this->musics.end()) {
		sf::Music* music = new sf::Music();

		/* Try to open a file */
		if(!music->openFromFile(filename)) {
			SPDLOG_ERROR("Cannot load {} music file", filename);
		}

		this->musics[name] = music;
	} else {
		SPDLOG_ERROR("Music is actually loaded!");
	}
}

void impl::MusicManager::play(const std::string& name) {
	sf::Music* music = this->musics[name];
	music->play();
}