#pragma once
#include "../eng/ENC.h"
#include "../eng/components/Transform.h"
#include "../eng/Input.h"
#include "../eng/Rand.h"


class Test4 : public eng::Component {
	eng::Transform* t;
	eng::Postion* p;

	sf::RectangleShape rc;
	eng::Vec2f vloc;
	eng::RGB color;
	uint8_t opacity;

public:
	void Init() override{
		color = eng::Rand::Color();
		t = getComponent<eng::Transform>();
		p = getComponent<eng::Postion>();
		opacity = eng::Rand::Int(0 , 256);
		int rand = eng::Rand::Int(0, 2);
		int rand2 = eng::Rand::Int(0, 2);
		vloc = Vec2f::RandomUnitVector() * 150 * Vec2f(rand == 0 ?  -1 : 1 , rand2 == 0 ? -1 : 1);
		color = eng::Rand::Color();
	}

	void Update() override {
		t->translate(vloc * Parent->getDeltaTime());
		opacity--;
		if (opacity <= 0) {
			Parent->destroy();
		}
	}

	void Draw() {
		rc.setFillColor(sf::Color(color.r, color.g, color.b, opacity));
		rc.setSize(sf::Vector2f(p->getSize().x , p->getSize().y));
		rc.setPosition( p->getPostion().x , p->getPostion().y);
		Parent->window->draw(rc);
	}

};

class Test3 : public eng::Component {
public:

	void Init() override {
	}

	void Update() override {
		if (eng::Input::MousePress(eng::Input::MouseButton::Right)) {
			
			initializeObject({ 
				(float)sf::Mouse::getPosition(*Parent->window).x ,
				(float)sf::Mouse::getPosition(*Parent->window).y
				}, { 5 , 5 })
				->addComponent<eng::Transform>()
				->addComponent<Test4>();
		}
	}

};