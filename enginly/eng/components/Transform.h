#pragma once
#include "../ENC.h"
#include "../eng/Input.h"

namespace eng {
	class Transform : public Component
	{
	private:
		Postion* pos;
	public:
		void Init() override {
			pos = &Parent->getComponent<Postion>();
		}
		void translate(eng::Vec2f vect) {
			eng::Vec2f v = pos->getPostion();
			pos->setPostion(
				v.x + vect.x,
				v.y + vect.y);
		}
		void translate(float x,  float y) {
			eng::Vec2f v = pos->getPostion();
			pos->setPostion(
				v.x + x ,
				v.y + y);
		}
	};
};