#pragma once
#include "../ENC.h"

namespace eng {
	class RectRenderer : public eng::Component
	{
	private:
		sf::RectangleShape shape;
		eng::Postion* p;
	public:
		void Init() {
			p = &Parent->getComponent<eng::Postion>();
			shape.setFillColor(sf::Color::Red);
			shape.setSize(sf::Vector2f(100, 100));
		}

		void Update() override {
			shape.setPosition(p->getPostion().x, p->getPostion().y);
		}

		void Draw() override {
			Parent->window->draw(shape);
		}
	};
};