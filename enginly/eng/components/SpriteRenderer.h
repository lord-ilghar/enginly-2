#pragma once
#include "../ENC.h"
#include "../Texture.h"

namespace eng {
	class SprieRenderer : public eng::Component {
	private:
		sf::Sprite sprite;
		eng::Postion* p;
		std::vector<std::vector<sf::IntRect>> rects;
		eng::Vec2i m_parts;
		sf::Texture texture;
		eng::Vector2<bool> fliped;

	public:

		SprieRenderer(std::string path, eng::Vec2i parts = eng::Vec2i(1, 1)) {
			m_parts = parts;
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
			sprite.setScale(std::floor(p->getSize().x / (texture.getSize().x / m_parts.x)),
				std::floor(p->getSize().y / (texture.getSize().y / m_parts.y)));
		}

		sf::Sprite getSprite() { return sprite; }

		void setRenderRect(eng::Vec2i rect) {
			sprite.setTextureRect(rects[rect.y][rect.y]);
		}

		void setRenderRect(int x , int y) {
			sprite.setTextureRect(rects[y][x]);
		}
		
		void flipX(bool check) {fliped.x = check;}
		void flipY(bool check) {fliped.y = check;}

	eng::Vec2i getSliceAmount() {
		return m_parts;
	}

		void Update() override {
			sprite.setPosition(p->getPostion().x, p->getPostion().y);
				sprite.setOrigin(
					(fliped.x ? 1 : 0) *
					sprite.getLocalBounds().width,
					(fliped.y ? 1 : 0) *
					sprite.getLocalBounds().height
					);
			sprite.setScale( 
				(fliped.x ? -1 : 1) *
				std::floor(p->getSize().x / (texture.getSize().x / m_parts.x)),
				(fliped.y ? -1 : 1) *
				std::floor(p->getSize().y / (texture.getSize().y / m_parts.y))
				);
			//TODO : ADD ROTAION!
			//sprite.setRotation(p->)
			/*
			if (fliped.x && !fliped.y) {
				p->getSize().y / (texture.getSize().y / m_parts.y));
			}else if (fliped.y && !fliped.x) {
				sprite.setScale(p->getSize().x / (texture.getSize().x / m_parts.x),
					-p->getSize().y / (texture.getSize().y / m_parts.y));
			}else if (fliped.y && fliped.x) {
				sprite.setScale(-p->getSize().x / (texture.getSize().x / m_parts.x),
					-p->getSize().y / (texture.getSize().y / m_parts.y));
			}
			else {

			}
			*/
			//sprite.setScale(3, 3);
			Parent->window->draw(sprite);
		}

	};
};