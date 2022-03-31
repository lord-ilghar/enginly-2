#pragma once
#include "../eng/ENC.h"
#include "../eng/Vector.h"
#include "../eng/Rand.h"
#include "../eng/components/Transform.h"

class Ball : public eng::Component {
	eng::Postion* p;
	sf::RectangleShape rc;
	sf::Text t;
	sf::Text t2;
	eng::Transform* transform;
	sf::Font f;
	int score1 = 0, score2 = 0;
public:
	std::string c = " none ";
	eng::Vec2f vlocity;
	void Init() override {
		if (!f.loadFromFile("C:/Users/HP/Downloads/Compressed/imgui-master/imgui-master/misc/fonts/Roboto-Medium.ttf")) throw;
		t.setFillColor(sf::Color::White);
		t.setPosition( (Parent->window->getSize().x / 4), 10.f);
		t.setCharacterSize(30);
		t.setFont(f);

		t2.setFillColor(sf::Color::White);
		t2.setPosition( Parent->window->getSize().x - (Parent->window->getSize().x / 4), 10.f);
		t2.setCharacterSize(30);
		t2.setFont(f);



		p = &Parent->getComponent<eng::Postion>();
		transform = &Parent->addComponent<eng::Transform>();
		rc.setFillColor(sf::Color::White);
		rc.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
	}

	void score() {
		vlocity = eng::Vec2f(0, 0);
		if (eng::Input::KeyPress(sf::Keyboard::Enter)) {
			p->setPostion(eng::Vec2f(Parent->window->getSize().x / 2, Parent->window->getSize().y / 2));
			vlocity = eng::Vec2f(4, 4);

			if (c == "1") {
				score1++;
			}
			else if(c == "2") {
				score2++;
			}
			c = "none";
		}
	}

	void Start() {
		vlocity = eng::Vec2f(4, 4);
	}
	void Update() override {
		t.setString(std::to_string(score1));
		t2.setString(std::to_string(score2));

		eng::Vec2f v = p->getPostion();
		transform->translate(vlocity);
		if (v.y >= Parent->window->getSize().y) {
			p->setPostion(v.x ,Parent->window->getSize().y - p->getSize().y);
			vlocity.y = -vlocity.y;
		}
		if (v.y <= 0) {
			p->setPostion(v.x , p->getSize().y)	;
			vlocity.y = -vlocity.y;
		}
		if (v.x >= Parent->window->getSize().x) {
			score();
		}
		if (v.x <= 0) {
			score();
		}
		rc.setPosition(
			v.x, v.y
		);
	}
	void Draw() override {
		Parent->window->draw(rc);
		Parent->window->draw(t);
		Parent->window->draw(t2);
	}
};