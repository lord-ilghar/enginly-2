#include "..\eng\Texture.h"

sf::Texture eng::Texture::LoadTexture(const char* path, Texture::Options options)
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(path))
		throw "error in loading texture";
	switch (options)
	{
	case eng::Texture::Options::SMOOTH:
		texture->setSmooth(true);
		break;
	case eng::Texture::Options::REPEATED:
		texture->setRepeated(true);
		break;
	}
	return *texture;
}
