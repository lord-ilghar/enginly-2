/*
#define __DEBUG__
#include "eng/Game.h"
#include "debugTools/debug.h"
#include "userComponents/Test3.h"
#include "eng/components/Collision.h"

using namespace eng;


class Eater : public eng::Component {
	eng::Transform* t = nullptr;
	eng::Postion* p = nullptr;
	sf::RectangleShape rc;
	eng::Vec2f postion;
	eng::Vec2f sizeBig;
	eng::CollisionBox* box;
	std::vector<eng::Object*> objs;
public:

	void Init() override {
		box = &Parent->getComponent<eng::CollisionBox>();
		t = &Parent->getComponent<eng::Transform>();
		p = t->getPostion();
		rc.setFillColor(sf::Color::Red);
		rc.setPosition(p->getPostion().x, p->getPostion().y);
		rc.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
	}

	void addEaten(eng::Object& obj) {
		objs.push_back(&obj);
	}

	void LightUpdate() override {
		rc.setPosition(p->getPostion().x, p->getPostion().y);
	}
	void Update() {
		postion = p->getPostion();
		sizeBig = p->getSize();
		t->translate(
			eng::Input::getAxis(eng::Input::Axis::Horizontal) * 100 * Parent->getDeltaTime(),
			eng::Input::getAxis(eng::Input::Axis::Vertical) * 100 * Parent->getDeltaTime()
		);

		for (int i = 0; i < objs.size(); i++) {

			eng::Vec2f pos = objs[i]->getComponent<eng::Postion>().getPostion();
			eng::Vec2f size = objs[i]->getComponent<eng::Postion>().getSize();

			ImGui::Begin("postions");

			ImGui::Text(pos.toString().c_str());
			ImGui::Text((pos + size).toString().c_str());
			ImGui::Text("---");

			ImGui::Text(postion.toString().c_str());
			ImGui::Text((postion + sizeBig).toString().c_str());

			ImGui::End();
			box->enterIntersection(&objs[i]->getComponent<CollisionBox>(), [&]() {
				rc.setFillColor(sf::Color::Blue);
				}
			);
			box->exitIntersection(&objs[i]->getComponent<CollisionBox>(), [&]() {
				rc.setFillColor(sf::Color::Red);
				}
			);
		}
	}
	void Draw() override {
		Parent->window->draw(rc);
	}
};

class Eaten : public eng::Component {
	eng::Transform* t = nullptr;
	eng::Postion* p = nullptr;
	sf::RectangleShape rc;
public:
	void Init() override {
		t = &Parent->getComponent<eng::Transform>();
		p = t->getPostion();
		rc.setFillColor(sf::Color::Blue);
		rc.setPosition(p->getPostion().x, p->getPostion().y);
		rc.setSize(sf::Vector2f(p->getSize().x, p->getSize().y));
	}
	void LightUpdate() override {
		rc.setPosition(p->getPostion().x, p->getPostion().y);
	}
	void Draw() override {
		Parent->window->draw(rc);
	}
};


int main() {
	Game* g = new Game(720, 360, "Hello");
	ObjectManager* manger = g->getmanger();
	auto& e = manger->addObject(Vec2f(100, 100), Vec2f(100, 100));
	auto& e2 = manger->addObject(Vec2f(200, 200), Vec2f(40, 40));
	auto& e3 = manger->addObject(Vec2f(150, 200), Vec2f(40, 40));
	e.addComponent<eng::Transform>()->addComponent<CollisionBox>()->addComponent<Eater>();
	e2.addComponent<eng::Transform>()->addComponent<CollisionBox>()->addComponent<Eaten>();
	e.getComponent<Eater>().addEaten(e2);
	//e.getComponent<Eater>().addEaten(e3);
	//e3.addComponent<eng::Transform>()->addComponent<Eaten>();
	g->run();
}
*/