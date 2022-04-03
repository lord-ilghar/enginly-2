#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "eng/components/RectRenderer.h"
#include "eng/components/Physics.h"
#include "eng/components/AudioManager.h"
#include "userComponents/Test.h"
#include "userComponents/Test2.h"

using namespace eng;



int main() {
	Game* g = new Game(720 , 400 , "Hello");
	ObjectManer* manger = g->getmanger();
	auto& e = manger->addObject(Vec2f(100 , 100) , Vec2f(50 , 50));
	e.addComponent<AudioManager>()->addComponent <Test2>();
	

	g->run();
}

