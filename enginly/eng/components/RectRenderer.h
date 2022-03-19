#pragma once
#include "../ENC.h"

class RectRenderer : public Component
{
private:
	sf::RectangleShape shape;
	Postion* p;
public:
	void Init() {
		p = &Parent->getComponent<Postion>();
	}

	void Start() override {
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

