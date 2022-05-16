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
#include "../eng/components/AudioManager.h"
int main()
{
    eng::Game* g = new eng::Game(800, 400, "test");
    eng::ObjectManer* manger = g->getmanger();
    g->setFPSLimit(60);
    auto& ball = manger->addObject(eng::Vec2f(g->getWindow().getSize().x / 2, g->getWindow().getSize().y / 2), eng::Vec2f(10.f, 10.f));
    eng::AudioManager::addSound("C:/Users/HP/source/repos/enginly/enginly/res/hit-pong.wav", "hit");
    eng::AudioManager::addSound("C:/Users/HP/source/repos/enginly/enginly/res/score-pong.wav", "score");

    ball.addComponent<Ball>();
    auto& platform1 = manger->addObject(eng::Vec2f(
        20.f,
        g->getWindow().getSize().y / 2.f), eng::Vec2f(5, 60));
    auto& platform2 = manger->addObject(eng::Vec2f(
        g->getWindow().getSize().x - 20.f,
        g->getWindow().getSize().y / 2.f), eng::Vec2f(5, 60));
    platform1.setTage("1");
    platform1.addComponent<eng::Transform>();
    platform1.addComponent<Platfrom>(&ball);

    platform2.setTage("2");
    platform2.addComponent<eng::Transform>();
    platform2.addComponent<Platfrom>(&ball);
    g->run();
    return 0;
}
*/