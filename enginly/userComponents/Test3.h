#pragma once
#include "../eng/ENC.h"
#include "../eng/Input.h"


class Test4 : public eng::Component {
public:

	void Init() override {
		CPRINT("init");
	}

};

class Test3 : public eng::Component {
public:

	void Init() override {
	}

	void Update() override {
		if (eng::Input::MousePress(eng::Input::MouseButton::Right)) {
			inislizeObject();
		}
	}

	void Draw() override {

	}

};