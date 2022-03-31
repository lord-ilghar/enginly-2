#pragma once
#include "../eng/ENC.h"
#include "../eng/Vector.h"
#include "../eng/Texture.h"


class Test : public eng::Component
{
private:
	sf::RenderWindow* w;
	sf::Sprite t;
	sf::Texture texture;
	eng::Postion* p;
public:
	void Init() override {
		w = Parent->window;
		p = &Parent->getComponent<eng::Postion>();
		texture = eng::Texture::LoadTexture(
			"C:/Users/HP/source/repos/enginly/enginly/res/1.jpg" 
			, eng::Texture::Options::REPEATED 

			);
		t.setTexture(texture);
		t.setPosition(p->getPostion().y, p->getPostion().x);
	}
	void Draw() override {
		w->draw(t);
	}
};

