#pragma once
#include <SFML/Graphics.hpp>

namespace eng {
	namespace Texture {
		enum class Options
		{
			SMOOTH , REPEATED
		};
		sf::Texture LoadTexture(const char* path, Texture::Options options = Options::SMOOTH);
	};
};