#pragma once
#include "../ENC.h"
#include "SpriteRenderer.h"

namespace eng {
	class Animation {
		sf::Clock Time;

	public:
		int maxFrame;
		int minFrame;
		eng::SprieRenderer spriteRenderer;
	virtual void loop() {}
	};
	class AnimationManger : eng::Component {
		std::vector<std::shared_ptr<Animation>> animations;
	public:

		void Init() override {
			for (size_t i = 0; i < animations.size(); i++) {
				animations[i]->spriteRenderer = Parent->getComponent<eng::SprieRenderer>();
			}
		}

		Animation addAnimation(int minRect , int maxRect , int TimeBetweenEachFrame) {
			std::shared_ptr<Animation> anim = std::make_shared<Animation>();
			anim->maxFrame = maxRect;
			anim->minFrame = minRect;
			anim->Time = TimeBetweenEachFrame;
			animations.emplace_back(anim);
		}

		void Draw() override {
			for (size_t i = 0; i < animations.size(); i++) {
				animations[i]->loop();
			}
		}

	};
}