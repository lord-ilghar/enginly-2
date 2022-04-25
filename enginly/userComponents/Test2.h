#pragma once
#include "eng/ENC.h"
#include "eng/components/AudioManager.h"
#include "eng/components/SpriteRenderer.h"
#include "eng/components/Animation.h"
#include "eng/Time.h"


class anim1 : eng::Animation {
public:
	void loop() override {

		spriteRenderer.setRenderRect(1 , )

	}
};


class Test2 : public eng::Component
{
	eng::SprieRenderer* sp;
	sf::Clock c;
	int frameCounter;
	int m_row;

public:
	void Init() override {
		sp = &Parent->getComponent<eng::SprieRenderer>();
	}
	void Update() override {
			if (c.getElapsedTime().asMilliseconds() > 100) {
				sp->setRenderRect(frameCounter , m_row);
				c.restart();
				frameCounter++;


				if (frameCounter == 10) {
					frameCounter = 0;
				}
			}
	}
};