#pragma once
#include "eng/ENC.h"
#include "eng/components/AudioManager.h"
#include "eng/Time.h"

class Test2 : public eng::Component
{
private:
	AudioManager* mg;
public:
	void Init() override {
		mg = &Parent->getComponent<AudioManager>();
		mg->addSound("C:/Users/HP/Documents/gg/Yamete Kudasai.wav" , "g");
	}
	void Update() override {
		//CPRINT(eng::Time::getDeltaTime());
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mg->getSound("g").play();
		}
	}
};

