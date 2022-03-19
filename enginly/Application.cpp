#define __DEBUG__
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "eng/ENC.h"
#include "eng/Game.h"
#include "../debugTools/debug.h"
#include "eng/components/RectRenderer.h"
#include "userComponents/Test.h"

int main()
{
   eng::Game *g = new eng::Game(600, 500, "test");
   ObjectManer* manger = g->getmanger();
   auto& e(manger->addObject(eng::Vec2f(20, 102)));
   auto& e2(manger->addObject(eng::Vec2f(1, 20)));
   //e.addComponent<Postion>(e);
   e.setTage("hii");
   e.addComponent<Transform>();
   e.addComponent<Test>();
   e.addComponent<RectRenderer>();
   e2.addComponent<RectRenderer>();
   g->run(60);
    return 0;
}
