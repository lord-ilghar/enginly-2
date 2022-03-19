#include "../eng/ENC.h"
#include "../debugTools/debug.h"


void ObjectManer::Update()
{
	for (auto& i : m_objects) {
		i->Update();
	}
}
void ObjectManer::Init()
{
	for (auto& i : m_objects) {
		i->Init();
	}
}
void ObjectManer::Start()
{
	for (auto& i : m_objects) {
		i->Start();
	}
}
std::shared_ptr<Object> ObjectManer::addObject()
{
	std::shared_ptr<Object> object = std::make_shared<Object>();
	m_objects.push_back(object);
	return object;
}

void Object::Update()
{
	for (auto& i : m_componentsArray) {
		i->Update();
	}
}
void Object::Init()
{
	for (auto& i : m_componentsArray) {
		i->Init();
	}
}
void Object::Start()
{
	for (auto& i : m_componentsArray) {
		i->Start();
	}
}

template<typename T>
inline void Object::addComponent()
{
		
}