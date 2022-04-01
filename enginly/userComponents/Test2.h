#pragma once
#include "eng/ENC.h"
#include "eng/Time.h"

class Test2 : public eng::Component
{
public:
	void Update() override {
		//CPRINT(eng::Time::getDeltaTime());
		CPRINT(Parent->getDeltaTime());
	}
};

