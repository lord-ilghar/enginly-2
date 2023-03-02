#pragma once
#include "../ECS.h"
#include "../Vector.h"
#include <functional>

namespace eng {
	class CollisionBox : public eng::Component {
		eng::Postion* postion;
		sf::FloatRect* box = nullptr;
	public:
		void Init() override {
			postion = getComponent<eng::Postion>();
			box = new sf::FloatRect();
			box->top = postion->getPostion().y;
			box->left = postion->getPostion().x;
			box->height = postion->getSize().y;
			box->width = postion->getSize().x;
		}
		void LightUpdate() override {
			box->top = postion->getPostion().y;
			box->left = postion->getPostion().x;
			box->height = postion->getSize().y;
			box->width = postion->getSize().x;
		}

		bool isIntersecting(CollisionBox* otherBox) const {
			return this->box->intersects(otherBox->getBox());
		}

		void enterIntersection(CollisionBox* otherBox, std::function<void()> eventFunction) {
			if (this->isIntersecting(otherBox)) {
				eventFunction();
			}
		}

		void exitIntersection(CollisionBox* otherBox, std::function<void()> eventFunction) {
			if (!this->isIntersecting(otherBox)) {
				eventFunction();
			}
		}

		sf::FloatRect& getBox() const {
			return *box;
		}
	};
}