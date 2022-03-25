#pragma once
#include "../eng/ENC.h"
#include "../eng/Vector.h"

class Test : public Component
{
private:
	sf::RenderWindow* w;
	sf::RectangleShape r;
	eng::Vec2f p;
	float heading;
public:
	void Init() override {
		w = Parent->window;
		r.setFillColor(sf::Color::White);
		r.setOrigin(sf::Vector2f(0 , 0));
		p =  eng::Vec2f(0, 1);
	}
	void Update() override {
	}
	void Draw() override {
		w->draw(r);
	}
};

