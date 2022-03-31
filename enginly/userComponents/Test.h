#pragma once
#include "../eng/ENC.h"
#include "../eng/Vector.h"
#include "../eng/Texture.h"


class Test : public eng::Component
{
private:
	sf::RenderWindow* w;
	eng::Postion* p;
	sf::RectangleShape t;
	eng::RigitBody* rg;
public:
	void Init() override {
		w = Parent->window;
		p = &Parent->getComponent<eng::Postion>();
		t.setFillColor(sf::Color::White);
		rg = &Parent->getComponent<eng::RigitBody>();
		//rg->applyForce(eng::Vec2f(0.f, 10.f));
	}

	void Update() override {
		if (eng::Input::MousePress(eng::Input::MouseButton::Left))
			rg->applyForce(eng::Vec2f(0.f, .3f));
		if (eng::Input::MousePress(eng::Input::MouseButton::Right))
			rg->applyForce(eng::Vec2f(0.f, -.3f));
		t.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
		t.setPosition(p->getPostion().x, p->getPostion().y);
	}

	void Draw() override {
		w->draw(t);
	}
};

