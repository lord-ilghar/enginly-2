#pragma once
#include <cmath>
#include <ctime>
#include "../ENC.h"

// NOTE : THIS Component is in its very early stages 
// and you should`t use it

namespace eng {
	class RigitBody : public eng::Component
	{
	private:
		eng::Vec2f vlocity;
		eng::Vec2f acc;
		float_t mass;
		eng::Postion* postion;
		void checkEdges() {
			eng::Vec2f pos = postion->getPostion();
			if (pos.y + postion->getSize().y >= Parent->window->getSize().y) {
				vlocity.y *= 0;
				postion->setPostion(pos.x  , Parent->window->getSize().y - postion->getSize().y);
			}
		};

	public:
		RigitBody(float_t mass = 1.f) { 
			if (mass <= 0) {
				throw "mass can not be less than 0";
			}
			this->mass = mass;
		}

		void Init() override {
			postion = &Parent->getComponent<eng::Postion>();
		}

		void applyForce(eng::Vec2f force) {
			acc += force / mass;
		}

		void Update() override {
			checkEdges();
			applyForce(eng::Vec2f(0, .3));
			vlocity += acc;
			acc.set(0, 0);			
			postion->setPostion(postion->getPostion() + vlocity);
		}
	};
};
