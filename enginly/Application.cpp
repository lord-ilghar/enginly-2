#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "eng/components/RectRenderer.h"
#include "eng/components/Physics.h"
#include "eng/components/AudioManager.h"
#include "eng/components/SpriteRenderer.h"
#include "userComponents/Test.h"
#include "userComponents/Test2.h"
#include "eng/components/Animation.h"
#include <fstream>
#include "json.hpp"
#include "userComponents/Test3.h"

using namespace eng;
int main() {
	Game* g = new Game(720, 360 , "Hello");
	ObjectManer* manger = g->getmanger();
	auto& e = manger->addObject(Vec2f(100, 100) , Vec2f(100 , 100));
	e.addComponent<Test3>();
	/*
	e.addComponent<eng::SprieRenderer>(
		"C:/Users/HP/source/repos/enginly/enginly/res/2.png",
		eng::Vec2i(10, 10))->addComponent<AnimationManger>()->addComponent<eng::Transform>()->addComponent<Test2>();
		*/
	g->run();
}
