#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "eng/components/SpriteRenderer.h"
#include "userComponents/Test2.h"
#include "userComponents/Test3.h"
#include "eng/components/Animation.h"
#include "eng/components/ShapesRenderer.h"
#include "eng/ECS.h"
#include "eng/components/Transform.h"
#include <fstream>
#include "json.hpp"

/*
class PilarManager : public eng::Component {
	std::vector<std::vector<eng::Object*>> m_pilars;
public:
	PilarManager(std::vector<std::vector<eng::Object*>> pilars){
		m_pilars = pilars;
	}
	void Init() override {

	}

	void Update() {
		for (size_t i = 0; i < m_pilars.size(); i++)
		{
			eng::Postion* pos = &m_pilars[i][0]->getComponent<eng::Postion>();
			//pos->setPostion(pos->getPostion().x+(100 * Parent->getDeltaTime()), pos->getPostion().y);
			if (pos->getPostion().x > Parent->window->getSize().x) { pos->setPostion(0, pos->getPostion().y); }
		}
	}

};

int main() {
	Game* g = new Game(720, 360 , "Animation");
	const eng::Vec2f pilarSize = { 100.f , 360.f };

	eng::ObjectManager* manger = g->getmanger();

	// LIMIT : -40 , 170
	auto& e = manger->addObject(Vec2f(0, -300 /2 - 60) , pilarSize);
	auto& e2 = manger->addObject(Vec2f(0, 300 / 2 + 60) , pilarSize);
	auto& e4 = manger->addObject(Vec2f(0, 360 / 2 + 60) , pilarSize);
	auto& e3 = manger->addObject(Vec2f(0,0) , Vec2f(0  , 0));



	e.addComponent<eng::Rectangle>(eng::Color::RGB(255, 255, 255, 255));
	e2.addComponent<eng::Rectangle>(eng::Color::RGB(255, 200, 100, 255));

	std::vector < std::vector < eng::Object* >> objects= { {&e , &e2} };

	e3.addComponent<PilarManager>(objects);
	g->run();
}

*/

int x, y;
sf::RectangleShape rc;
void Draw(sf::RenderWindow* win) {
	rc.setFillColor(sf::Color::Blue);
	x += 1;
	y += 1;
	rc.setSize(sf::Vector2f(100,100));
	rc.setPosition(100 , 100);
	win->draw(rc);
}

int main() {
	eng::Game* game = new eng::Game(720, 480, "GG");
	game->enableAdditionalFeatures(true);
	game->setAdditionalDraw(Draw);
	game->run();
}

