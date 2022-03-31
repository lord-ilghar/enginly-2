/*
#define __DEBUG__
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "../eng/ENC.h"
#include "../eng/Game.h"
#include "../debugTools/debug.h"
#include "../userComponents/Platform.h"
#include "../userComponents/Ball.h"
#include "../eng/components/Transform.h"
int main()
{
    eng::Game* g = new eng::Game(800, 400, "test");
    eng::ObjectManer* manger = g->getmanger();
    auto& ball = manger->addObject(eng::Vec2f(g->getWindow().getSize().x / 2, g->getWindow().getSize().y / 2), eng::Vec2f(10.f, 10.f));
    ball.addComponent<Ball>();
    auto& platform1 = manger->addObject(eng::Vec2f(
        20.f,
        g->getWindow().getSize().y / 2.f), eng::Vec2f(5, 60));
    auto& platform2 = manger->addObject(eng::Vec2f(
        g->getWindow().getSize().x - 20.f,
        g->getWindow().getSize().y / 2.f), eng::Vec2f(5, 60));
    platform1.setTage("1");
    platform2.setTage("2");
    platform2.addComponent<eng::Transform>();
    platform1.addComponent<eng::Transform>();
    platform1.addComponent<Platfrom>(&ball);
    platform2.addComponent<Platfrom>(&ball);
    g->run(60);
    return 0;
}*/
