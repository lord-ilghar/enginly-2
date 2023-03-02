#pragma once
#include "../ECS.h"
#include "../Color.h"

namespace eng {
	class Shape : public eng::Component{
	protected:
		eng::Postion* postion;
		eng::Color::RGB color;
	public:

		Shape(eng::Color::RGB Color) {
			color = Color;
		}

		void Init() override {
			postion = getComponent<Postion>();
		}
		void setColor(eng::Color::RGB newColor) { color = newColor; }
		eng::Color::RGB getColor() const { return color; }
	}; // shapes 



	class Rectangle : public Shape{
		sf::RectangleShape rc;
	public:
		Rectangle(eng::Color::RGB color) :Shape(color) {}


		void Update() override {
			rc.setPosition(postion->getPostion().x, postion->getPostion().y);
			rc.setRotation(postion->getRotaion());
			rc.setSize(sf::Vector2f(postion->getSize().x , postion->getSize().y));
		}
		void Draw() override {

			rc.setFillColor(sf::Color(color.r, color.g, color.b, color.alpha));
			Parent->window->draw(rc);
		}
	};
	class Circle : public Shape {
		sf::CircleShape shape;

	public:
		Circle(eng::Color::RGB color) :Shape(color) {}


		void Update() override {
			shape.setPosition(postion->getPostion().x, postion->getPostion().y);
			shape.setRotation(postion->getRotaion());
			shape.setRadius(postion->getSize().x / 2.f);
			//CPRINT((int)m_color.alpha);
		}
		void Draw() override {
			shape.setFillColor(sf::Color(color.r, color.g, color.b , color.alpha));
			Parent->window->draw(shape);
		}
	};
	class Polygon : public Shape {
		sf::CircleShape shape;


	public:

		Polygon(eng::Color::RGB color , uint32_t points) :Shape(color) {
			shape.setPointCount(points);
		}

		void Update() override {
			shape.setPosition(postion->getPostion().x, postion->getPostion().y);
			shape.setRotation(postion->getRotaion());
			shape.setRadius(postion->getSize().x / 2.f);
		}
		void Draw() override {
			shape.setFillColor(sf::Color(color.r, color.g, color.b, color.alpha));
			Parent->window->draw(shape);
		}
	};
}