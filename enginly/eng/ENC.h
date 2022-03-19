#pragma once
#define __DEBUG__
#include <vector>
#include <array>
#include <bitset>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../debugTools/debug.h"
#include <string>
#include "Vector.h"


#define MaxComponents 50

unsigned int inline getComponentID() {
	static unsigned int ID = 0;
	return ID++;
}

template<typename T>
unsigned int inline getComponentTypeID() noexcept {
	static unsigned int typeID = getComponentID();
	return typeID;
}
class ObjectManer;
class Object;
class Component;
class Postion;

class Object {
private:
	std::array<Component*, MaxComponents> m_componentsArray;
	std::bitset<MaxComponents> m_componentCheck;
	std::vector<std::string> tags;
public:
	sf::RenderWindow* window;
	ObjectManer* manager;

	void Update();
	void Start();
	void Draw();

	//seters & geters
	void setTage(std::string newTag) {
		tags.push_back(newTag);
	}
	bool checkTag(std::string tag) {
		for (auto& i : tags) {
			return tag == i;
		}
	}

	template <typename T , typename... Params>
	T& addComponent(Params&&... params) {
		T* c(new T(std::forward<Params>(params)...));
		c->Parent = this;
		m_componentsArray[getComponentTypeID<T>()] = c;
		m_componentCheck[getComponentTypeID<T>()] = true;
		c->Init();
		return *c;
	}
		
	template<typename T>
	T& getComponent() {
		auto ptr(m_componentsArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

class ObjectManer
{
private:
	sf::RenderWindow* m_window;
public:
	ObjectManer(sf::RenderWindow* window) :m_window(window){};
	void Update();
	void Start();
	void Draw();
	Object& addObject(eng::Vec2f pos) {
		Object* object = new Object();
		std::unique_ptr<Object> uPtr{ object };
		object->window = m_window;
		object->manager = this;
		m_objects.push_back(std::move(uPtr));
		object->addComponent<Postion>(pos);
		return *object;
	}
private:
	std::vector<std::unique_ptr<Object>> m_objects;
};

class Component {
protected:
	// Component utility functions
public:
	Object* Parent;
	virtual void Update() {}
	virtual void Init() {}
	virtual void Start() {}
	virtual void Draw() {}
};

class Postion : public Component
{
private:
	eng::Vec2f postion;
public:
	Postion(int32_t x, int32_t y) {
		postion.x = x;
		postion.y = y;
	}
	Postion(eng::Vec2f pos) {
		postion = pos;
	}
	Postion() {
		postion = eng::Vec2f(0.f, 0.f);
	}
	void setPostion(int32_t x, int32_t y) {
		postion.x = x;
		postion.y = y;
	}
	void setPostion(eng::Vec2f pos) {
		postion = pos;
	}
	void setPostion() {
		postion = eng::Vec2f(0.f, 0.f);
	}

	eng::Vec2f getPostion() const {
		return postion;
	}
};