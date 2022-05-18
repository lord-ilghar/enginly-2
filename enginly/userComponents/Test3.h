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
	int32_t opacity;


public:
	void Init() override{
		color = eng::Rand::Color();
		t = getComponent<eng::Transform>();
		p = getComponent<eng::Postion>();
		opacity = eng::Rand::Int(0 , 256);
		int rand = eng::Rand::Int(0, 2);
		int rand2 = eng::Rand::Int(0, 2);
		vloc = eng::Vec2f::RandomUnitVector() * 150 * eng::Vec2f::RandomDiraction();
		color = eng::Rand::Color();
	}

	void Update() override {
		t->translate(vloc * Parent->getDeltaTime());
		opacity--;
	}

	void LightUpdate() override {
		if (opacity <= 0 || !isParentInWindowVeiw()) {
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
	eng::Vec2f size;
public:
	Test3(eng::Vec2f size) : size(size)  {

	}
	void Init() override {
	}

	void Update() override {
		if (eng::Input::KeyPress(eng::Input::KeyBordButton::Enter)) {
			
			initializeObject({ 
				100.f ,
				100.f
				}, size)	
				->addComponent<eng::Transform>()
				->addComponent<Test4>();
		}
	}

};