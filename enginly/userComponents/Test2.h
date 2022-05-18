#pragma once
#include "eng/ENC.h"
#include "eng/components/AudioManager.h"
#include "eng/components/Transform.h"
#include "eng/components/SpriteRenderer.h"
#include "eng/components/Animation.h"
#include "eng/Time.h"

using namespace eng;

class Test2 : public eng::Component
{
	eng::SprieRenderer* sp;
	eng::AnimationManger* mg;
	eng::Transform* ts;

	sf::Clock c;
	int frameCounter;
	int m_row;

public:
	void Init() override {
		sp = getComponent<eng::SprieRenderer>();
		mg = getComponent<eng::AnimationManger>();
		ts = getComponent<eng::Transform>();
		sp->setRenderRect(0, 0);

		mg->addAnimation("idel", { 0 , 0}, { 9 ,  0}, 100);
		mg->addAnimation("fire", { 0 , 3}, { 9 ,  3}, 100);
		mg->addAnimation("ready", { 0 , 1}, { 9 ,  1}, 100);
		mg->addAnimation("walk", { 0 , 2}, { 9 ,  2}, 100);
	}

	void Update() override {
		if (Input::MousePress(Input::MouseButton::Left)) {
			mg->PlaySingleAnimation("fire");
		}
		if (!mg->isAnimationPlaying("fire")) {
			if (Input::KeyPress(sf::Keyboard::D)) {
				mg->PlaySingleAnimation("walk");
				ts->translate(200 * Parent->getDeltaTime(), 0);
				sp->flipX(false);
			}
			else if (Input::KeyPress(sf::Keyboard::A)) {
				mg->PlaySingleAnimation("walk");
				ts->translate(-200 * Parent->getDeltaTime(), 0);
				sp->flipX(true);
			}
			else {
				mg->PlaySingleAnimation("idel");
			}
		}
	}

};