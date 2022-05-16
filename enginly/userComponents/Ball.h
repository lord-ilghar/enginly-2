#pragma once
#include "../eng/ENC.h"
#include "../eng/Vector.h"
#include "../eng/Rand.h"
#include "../eng/components/Transform.h"
#include "../eng/components/AudioManager.h"

class Ball : public eng::Component {
	eng::Postion* p;
	sf::RectangleShape rc;
	sf::Text t;
	sf::Text t2;
	eng::Transform* transform;
	sf::Font f;
	int score1 = 0, score2 = 0;
	bool soundPlayed; 
private:
	void pickRandomDiration() {
		vlocity = eng::Vec2f(4, 4) * eng::Vec2f::RandomDiraction();
	}
public:
	std::string c = " none ";
	eng::Vec2f vlocity;
	void Init() override {
		soundPlayed = false;
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
		Parent->addComponent<eng::Transform>();
		transform = &Parent->getComponent<eng::Transform>();
		rc.setFillColor(sf::Color::White);
		rc.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
	}

	void score() {
		vlocity = eng::Vec2f(0, 0);
		if(!soundPlayed) eng::AudioManager::getSound("score").play() ;
		soundPlayed = true;
		if (eng::Input::KeyPress(sf::Keyboard::Enter)) {
			p->setPostion(eng::Vec2f(Parent->window->getSize().x / 2, Parent->window->getSize().y / 2));
			pickRandomDiration();
			soundPlayed = false;
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
		pickRandomDiration();
	}
	void Update() override {
		t.setString(std::to_string(score1));
		t2.setString(std::to_string(score2));

		eng::Vec2f v = p->getPostion();
		transform->translate(vlocity);
		if (v.y >= Parent->window->getSize().y) {
			p->setPostion(v.x ,Parent->window->getSize().y - p->getSize().y);
			vlocity.y = -vlocity.y;
			eng::AudioManager::getSound("hit").play();
		}
		if (v.y <= 0) {
			eng::AudioManager::getSound("hit").play();
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