#pragma once
#include "../eng/ENC.h"
#include "../eng/Vector.h"
#include "../eng/Input.h"
#include "../eng/ENC.h"
#include "../eng/components/Transform.h"
#include "Ball.h"

class Platfrom : public eng::Component
{
private:
	sf::RenderWindow* w;
	eng::Postion* p;
	sf::RectangleShape rc;
	eng::Object* object;
	eng::Transform* transform;
	eng::Vec2f v;
	Ball* b;
	eng::Postion* ballP;
	eng::AudioManager* mg;

public:
	Platfrom(eng::Object* o) :object(o){
	}
	void Init() override {
		v.y = 5;
		w = Parent->window;
		p = &Parent->getComponent<eng::Postion>();
		mg = &Parent->getComponent<eng::AudioManager>();

		mg->addSound("C:/Users/HP/source/repos/enginly/enginly/res/hit-pong.wav", "hit");


		transform = &Parent->getComponent<eng::Transform>();
		rc.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
		rc.setFillColor(sf::Color::White);
		b = &object->getComponent <Ball>();
		ballP = &object->getComponent <eng::Postion>();
	}
	void Update() override {
		rc.setPosition(p->getPostion().x, p->getPostion().y);
		if (Parent->checkTag("1")) {
			transform->translate(0, eng::Input::getAxis(eng::Input::Axis::Vertical) * v.y);
		}
		if (Parent->checkTag("2")) {
			if (eng::Input::KeyPress(sf::Keyboard::F)) transform->translate(v);
			else if (eng::Input::KeyPress(sf::Keyboard::R)) transform->translate(0, -v.y);
			else transform->translate(0, 0);
		}
		eng::Vec2f ballp = ballP->getPostion();
			if (
				p->getPostion().y <= ballp.y &&
				p->getPostion().y + p->getSize().y >= ballp.y + ballP->getSize().y &&
				(p->getPostion().x == ballp.x ||
				p->getPostion().x == ballp.x + ballP->getSize().x)
				) {
				mg->getSound("hit").play();
				if (Parent->checkTag("1")) {
					b->c = "1";
				}
				else if (Parent->checkTag("2"))
				{
					b->c = "2";
				}
				b->vlocity.x = -b->vlocity.x;
			}
	}
	void Draw() override {
		w->draw(rc);
	}
};



