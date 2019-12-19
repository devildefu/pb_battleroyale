#include <managers/musicmanager.hpp>

impl::MusicManager::~MusicManager() {
	SPDLOG_INFO("Cleaning music");

	clear();
	current_music = nullptr;
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
	current_music = music;
}

bool impl::MusicManager::exists(const std::string& name) {
	return !(this->musics.find(name) == this->musics.end());
}

void impl::MusicManager::clear() {
	for(auto&& [key, val] : this->musics) {
		delete val;
	}
}

void impl::MusicManager::stop() {
	if(current_music) current_music->stop();
}

void impl::MusicManager::pause() {
	if(current_music) current_music->pause();
}

void impl::MusicManager::resume() {
	if(current_music) current_music->play();
}

void impl::MusicManager::set_volume(float volume) {
	if(current_music) current_music->setVolume(volume);
}