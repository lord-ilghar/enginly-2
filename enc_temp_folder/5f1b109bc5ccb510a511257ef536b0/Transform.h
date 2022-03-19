#pragma once
#include "../ENC.h"
#include "../eng/Input.h"

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
			v.x + eng::Input::getAxis(eng::Input::Axis::Horizontal) * 2,
			v.y + eng::Input::getAxis(eng::Input::Axis::Horizontal) * 2);
	}
};

