#pragma once
#include "../eng/ENC.h"
#include "../eng/components/Transform.h"
#include "../eng/Input.h"
#include "../eng/Rand.h"


class Test4 : public eng::Component {
	eng::Transform* t;
	eng::Postion* p;

	sf::RectangleShape rc;


public:


	void Init() override{
		eng::RGB color = eng::Rand::Color();
		t = getComponent<eng::Transform>();
		p = getComponent<eng::Postion>();
		rc.setFillColor(sf::Color(color.r, color.g, color.b));
	}

	void Update() override {
		t->translate(100 * Parent->getDeltaTime(), 0);
	}

	void Draw() {
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
			initializeObject({ 100 , 100 }, { 20 , 20 })
				->addComponent<eng::Transform>()
				->addComponent<Test4>();
		}
	}

	void Draw() override {

	}

};