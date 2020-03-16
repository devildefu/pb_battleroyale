#include <managers/musicmanager.hpp>

impl::MusicManager::~MusicManager() {
	SPDLOG_INFO("Cleaning music");

	clear();
	current_music = nullptr;
}

bool impl::MusicManager::load(const std::string& name, const std::string& filename) {
	bool status = true;
	if(!exists(name)) {
		sf::Music* music = new sf::Music;

		/* Try to open a file */
		if(!music->openFromFile(filename)) {
			SPDLOG_ERROR("Cannot load {} music file", filename);
			status = false;
		}

		this->musics[name] = music;
	} else {
		SPDLOG_ERROR("Music is actually loaded!");
		status = false;
	}

	return status;
}

bool impl::MusicManager::play(const std::string& name) {
	sf::Music* music = this->musics[name];
	if(!music) return false;
	
	music->play();
	music->setVolume(volume);
	current_music = music;
	return true;
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
	if(!current_music) return;
	current_music->stop();
}

void impl::MusicManager::pause() {
	if(!current_music) return;
	current_music->pause();
}

void impl::MusicManager::resume() {
	if(!current_music) return;
	current_music->play();
}

void impl::MusicManager::set_volume(float volume) {
	if(!current_music) return;

	this->volume = volume;
	current_music->setVolume(volume);
}