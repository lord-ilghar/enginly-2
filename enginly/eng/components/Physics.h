#pragma once
#include <cmath>
#include <ctime>
#include "../ENC.h"
namespace eng {
	class RigitBody : public eng::Component
	{
	private:
		eng::Vec2f vlocity;
		eng::Vec2f acc;
		float_t mass;
		eng::Postion& postion;

	public:
		void Init() override {
			postion = Parent->getComponent<eng::Postion>();
		}
		void applyForce(eng::Vec2f force) {
			acc + force;
		}
		void Update() override {
			postion.setPostion(postion.getPostion() + vlocity);
		}
	};
};
