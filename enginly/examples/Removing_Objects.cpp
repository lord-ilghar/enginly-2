/*
#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "userComponents/Test3.h"

using namespace eng;
int main() {
	Game* g = new Game(720, 360, "Hello");
	ObjectManager* manger = g->getmanger();
	auto& e = manger->addObject(Vec2f(100, 100), Vec2f(100, 100));
	e.addComponent<Test3>(eng::Vec2f(5, 5));
	g->run();
}
*/