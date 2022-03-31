#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "eng/components/RectRenderer.h"
#include "eng/components/Physics.h"
#include "userComponents/Test.h"

using namespace eng;



int main() {
	Game* g = new Game(720 , 400 , "Hello");
	ObjectManer* manger = g->getmanger();
	auto& e = manger->addObject(Vec2f(100 , 100) , Vec2f(50 , 50));
	e.addComponent<eng::RigitBody>(1.f);
	e.addComponent<Test>();
	

	

	g->run(60);

}