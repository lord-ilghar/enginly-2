#pragma once
#include "../ENC.h"
#include "../Texture.h"

namespace eng {
	class SprieRenderer : public eng::Component {
	private:
		sf::Sprite sprite;
		eng::Postion* p;
		std::vector<std::vector<sf::IntRect>> rects;
		eng::Vec2i parts;
		sf::Texture texture;

	public:

		SprieRenderer(std::string path, eng::Vec2i parts = eng::Vec2i(1, 1)) {
			texture.loadFromFile(path.c_str());
			sprite.setTexture(texture);
			for (size_t y = 0; y < texture.getSize().y / parts.y; y++) {
				std::vector<sf::IntRect> rc;
				for (rsize_t x = 0; x < texture.getSize().x / parts.x; x++ ) {
					//rects[y].push_back();
					rc.push_back(sf::IntRect(x * texture.getSize().x / parts.x,
						y * texture.getSize().y / parts.y, texture.getSize().x / parts.x,
						texture.getSize().y / parts.y));
					//std::cout << "X : " << rc[x].left << " Y : " << rc[x].top << "\n";
				}
				rects.push_back(rc);
			}

		}

		void Init() override {
			p = &Parent->getComponent<eng::Postion>();
		}

		sf::Sprite getSprite() { return sprite; }

		void setRenderRect(eng::Vec2i rect) {

		}

		void setRenderRect(int x , int y) {
			sprite.setTextureRect(rects[y][x]);
		}

		void Update() override {
			sprite.setPosition(p->getPostion().x, p->getPostion().y);
			sprite.setScale(3, 3);
			Parent->window->draw(sprite);
		}

	};
};