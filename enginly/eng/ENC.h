#pragma once
#include <vector>
#include <array>
#include <bitset>
#include <memory>
#include <SFML/Graphics.hpp>

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

class Component {
public:
	Object* Parent;
	virtual void Update(){}
	virtual void Init(){}
	virtual void Start(){}
};

class Component2;
class Component3;

class Object {
private:
	std::array<std::shared_ptr<Component>, MaxComponents> m_componentsArray;
public:
	void Update();
	void Init();
	void Start();
	template <typename T>
	void addComponent();
};

class ObjectManer
{
private:
	sf::RenderWindow* m_window;
public:
	ObjectManer(sf::RenderWindow* window) :m_window(window){};
	void Update();
	void Init();
	void Start();
	std::shared_ptr<Object> addObject();

private:
	std::vector<std::shared_ptr<Object>> m_objects;
};

