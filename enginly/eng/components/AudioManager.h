#pragma once
#include "../ENC.h"
#include <unordered_map>
#include <SFML/Audio.hpp>

namespace eng {
	namespace AudioManager
	{
		 std::unordered_map<std::string, sf::Sound> Audios;
		void addSound(std::string path, std::string key) {
			sf::SoundBuffer* buffer = new sf::SoundBuffer();
			sf::Sound sound;
			if (!(*buffer).loadFromFile(path)) {
				CERR("ERROR in loading file!");
				throw;
			}
			sound.setBuffer(*buffer);
			Audios[key] = sound;
		}
		sf::Sound& getSound(std::string key) { return Audios[key]; }
		void removeSound(std::string key) {
			delete Audios[key].getBuffer();
			Audios.erase(key);
		}
	};	
}