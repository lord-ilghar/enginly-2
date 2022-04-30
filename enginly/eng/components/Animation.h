#pragma once
#include "../ENC.h"
#include "SpriteRenderer.h"

namespace eng {
	class Animation {
		sf::Clock clock;
	public:
		eng::Vec2i frame;
		int Time;
		eng::Vec2i maxFrame;
		eng::Vec2i minFrame;
		eng::SprieRenderer* spriteRenderer;
		bool shouldPlay;
		bool finished;

		void Init() {
			shouldPlay = false;
			finished = true;
		}
	void loop() {
		if (clock.getElapsedTime().asMilliseconds() >= Time) {
			clock.restart();
			if (frame.x >= maxFrame.x + 1 && frame.y >= maxFrame.y) {
				frame = minFrame;
				finished = true;
			}
			if (frame.x >= spriteRenderer->getSliceAmount().x) {
				frame.y++;
				frame.x = 0;
			}
			spriteRenderer->setRenderRect(frame.x, frame.y);
			frame.x++;
		}
	}
	};


	class AnimationManger : public eng::Component {
		std::vector<std::shared_ptr<Animation>> animations;
		std::unordered_map<std::string, std::shared_ptr<Animation>> animation_map;

		void stopAll() {
			for (size_t i = 0; i < animations.size(); i++) {
				animations[i]->shouldPlay = false;
			}
		}

	public:

		void PlaySingleAnimation(std::string AnimationName) {
			stopAll();
			animation_map[AnimationName]->shouldPlay = true;
			animation_map[AnimationName]->finished = false;
		}
		/*
		*/
		void stopAnimation(std::string AnimationName) {animation_map[AnimationName]->shouldPlay = false;}

		void changeFrameTime(std::string AnimationName, uint32_t FrameTimeMS) { animation_map[AnimationName]->Time = FrameTimeMS; }

		bool isAnimationPlaying(std::string AnimatioName) {
			return !animation_map[AnimatioName]->finished;
		}

		void forceChangeFrame(std::string AnimationName, eng::Vec2i Frame) { 
			std::shared_ptr<Animation> anim = animation_map[AnimationName];
			if (Frame < anim->minFrame || Frame > anim->maxFrame) {
				throw "Frame Needs to stay in MaxFrame and MinFrame bounds";
				return;
			}
			anim->frame = Frame;
		}

		void addAnimation(std::string name ,eng::Vec2i minRect, eng::Vec2i maxRect, uint32_t TimeBetweenEachFrameMS) {
			std::shared_ptr<Animation> anim = std::make_shared<Animation>();
			anim->maxFrame = maxRect;
			anim->minFrame = minRect;
			anim->Time = TimeBetweenEachFrameMS;
			anim->frame = minRect;
			anim->spriteRenderer = &Parent->getComponent<SprieRenderer>();
			animations.emplace_back(anim);
			animation_map[name] = anim;
			anim->Init();
		}

		void Draw() override {
			for (size_t i = 0; i < animations.size(); i++) {
				if (animations[i]->shouldPlay) {
					animations[i]->loop();
				}
			}
		}

	};
}