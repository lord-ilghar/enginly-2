#pragma once
#include "../eng/ENC.h"
#include "../eng/components/Transform.h"


class Test : public Component
{
	Transform* t;
public:
	void Init() override {
		t = &Parent->getComponent<Transform>();
	}
	void Update() override {
		t->translate(eng::Vec2f(1 , 0));
	}
};

