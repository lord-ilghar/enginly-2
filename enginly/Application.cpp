#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "eng/components/RectRenderer.h"
#include "eng/components/Physics.h"

using namespace eng;

int main() {
	Game* g = new Game(720 , 400 , "Hello");
	ObjectManer* manger = g->getmanger();

	g->run(60);

}