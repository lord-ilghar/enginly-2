#pragma once
#include "../ECS.h"

namespace eng {
	class RectRenderer : public eng::Component
	{
	private:
		sf::RectangleShape shape;
		eng::Postion* p;
		sf::Color color;
	public:
		RectRenderer(sf::Color color) : color(color) , p(nullptr) , shape(sf::RectangleShape()) {}

		void Init() {
			p = &Parent->getComponent<eng::Postion>();
			shape.setFillColor(color);
			shape.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
		}

		void Update() override {
			shape.setPosition(p->getPostion().x, p->getPostion().y);
		}

		void Draw() override {
			Parent->window->draw(shape);
		}
	};
};