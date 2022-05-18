#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "eng/components/SpriteRenderer.h"
#include "userComponents/Test2.h"
#include "userComponents/Test3.h"
#include "eng/components/Animation.h"
#include "eng/ENC.h"
#include "eng/components/Transform.h"
#include <fstream>
#include "json.hpp"

int main() {
	Game* g = new Game(720, 360 , "Animation");
	eng::ObjectManager* manger = g->getmanger();
	/*
	auto& e = manger->addObject(Vec2f(100, 100) , Vec2f(100 , 100));
	auto& e2 = manger->addObject(Vec2f(0, 0), Vec2f(1, 1));

	e.addComponent<eng::SprieRenderer>(
		"C:/Users/HP/source/repos/enginly/enginly/res/2.png",
		eng::Vec2i(10, 10))->
		addComponent<eng::AnimationManger>()
		->addComponent<eng::Transform>()
		->addComponent<Test2>();
	*/
	g->run();
}