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
#include <unordered_map>

#define MaxComponents 50
namespace eng {
unsigned int inline getComponentID() {
	static unsigned int ID = 0;
	return ID++;
}

template<typename T>
unsigned int inline getComponentTypeID() noexcept {
	static unsigned int typeID = getComponentID();
	return typeID;
}
class Object;
class ObjectManager;
class Component;
class Postion;

class ObjectManager
{
public:

	void Draw();
	void Update(const float_t& deltaTime);
	void Start();

	ObjectManager(sf::RenderWindow* window,eng::Vec2i simulationDistance = eng::Vec2i( 200 , 200 )) :m_window(window) , m_simulationDistance(simulationDistance){};
	Object& addObject(const eng::Vec2f& pos, const eng::Vec2f& size);
	void refresh();

	//setters and getters
	void setsimulationDistance(const eng::Vec2i& sim) { m_simulationDistance = sim; }
	int32_t ObjectsAmount() const { return m_objects.size(); }

private:
	sf::RenderWindow* m_window;
	eng::Vec2i m_simulationDistance;
	bool isAlive;
	std::vector<std::unique_ptr<Object>> m_objects;
};

// object template
class Object {
public:
	ObjectManager* manager;
	sf::RenderWindow* window;
	bool getIsActive() const { return isActive; }
	void destroy();

	void Update();
	void Start();
	void Draw();
	void LightUpdate();
	void FixedUpdate();

	//seters & geters
	void setTage(const std::string& newTag) { tags[newTag] = 1; }
	bool checkTag(const std::string& tag) const { return (tags.find(tag) != tags.end()); }
	float_t getDeltaTime() const { return deltaTime; }
	void setDeltaTime(float_t const &time) { deltaTime = time; }

	template <typename T, typename... Params>
	Object* addComponent(Params&&... params) {
		T* c(new T(std::forward<Params>(params)...));
		c->Parent = this;
		std::unique_ptr<Component> Uptr{ c };
		m_components.emplace_back(std::move(Uptr));
		m_componentsArray[getComponentTypeID<T>()] = c;
		m_componentCheck[getComponentTypeID<T>()] = true;
		c->Init();
		return this;
	}

	template<typename T>
	T& getComponent() const {
		auto ptr(m_componentsArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
	template<typename T>
	bool hasComponent() const {return m_componentCheck[getComponentTypeID<T>()];}
private:
	std::array<Component*, MaxComponents> m_componentsArray;
	std::bitset<MaxComponents> m_componentCheck;
	std::vector<std::unique_ptr<Component>> m_components;
	std::unordered_map<std::string, bool> tags;
	float_t deltaTime;
	bool isActive = true;
};

//Component Template
class Component {
public:
	Object* Parent;

	virtual void Update() {}
	virtual void LightUpdate() {}
	virtual void Init() {}
	virtual void Start() {}
	virtual void Draw() {}
	virtual void FixedUpdate(){}

protected:
	// Component utilites
	int deltaTime() const {return Parent->getDeltaTime();}
	eng::Object* initializeObject(eng::Vec2f pos , eng::Vec2f size) {return &Parent->manager->addObject(pos , size);}
	bool isParentInWindowVeiw() const;
	template<typename T>
	T* getComponent() {return &Parent->getComponent<T>();}
	void destroy() { Parent->destroy(); }

};






class Postion : public Component
{
private:
	eng::Vec2f postion;
	eng::Vec2f size;
	float rotaion;
public:
	Postion(eng::Vec2f pos , eng::Vec2f size) : postion(pos) , size(size) , rotaion(0) {}
	void setPostion(float x, float y) {
		postion.x = x;
		postion.y = y;
	}
	void setPostion(eng::Vec2f pos) {
		postion =  pos;
	}
	void setPostion() {
		postion = eng::Vec2f(0.f, 0.f);
	}

	void setSize(eng::Vec2f newSize) {
		size = newSize;
	}

	void setSize(float w, float h) {
		size.x = w;
		size.y = h;
	}

	eng::Vec2f getPostion() const {
		return postion;
	}
	eng::Vec2f getSize() const {
		return size;
	}
};
};