#include "../eng/ENC.h"
#include "../debugTools/debug.h"


void eng::ObjectManager::Update(const float_t& deltaTime)
{
	for (int i = 0; i < m_objects.size(); i++) {
		eng::Vec2f postion = m_objects[i]->getComponent<Postion>().getPostion();
		eng::Vec2f size = m_objects[i]->getComponent<Postion>().getSize();
		if (i < m_objects.size() && -m_simulationDistance.x < postion.x + size.x &&
			m_simulationDistance.x + m_window->getSize().x > postion.x &&
			-m_simulationDistance.y < postion.y + size.y && 
			m_simulationDistance.y + m_window->getSize().y > postion.y
			) {
			m_objects[i]->setDeltaTime(deltaTime);
			m_objects[i]->Update();
		}if (i < m_objects.size()) { m_objects[i]->LightUpdate(); }
		else continue;
		if (i < m_objects.size() && 0 < postion.x + size.x &&
			m_window->getSize().x > postion.x &&
			0 < postion.y + size.y &&
			m_window->getSize().y > postion.y
			) {
			m_objects[i]->Draw();
		}
		else continue;
	}
}


void eng::ObjectManager::Start()
{
	for (int i = 0; i < m_objects.size(); i++) {
		m_objects[i]->Start();
	}
}

eng::Object& eng::ObjectManager::addObject(const eng::Vec2f& pos,const eng::Vec2f& size)
{
	Object* object = new Object();
	std::unique_ptr<Object> uPtr{ object };
	object->window = m_window;
	object->manager = this;
	m_objects.emplace_back(std::move(uPtr));
	object->addComponent<Postion>(pos , size);
	return *object;
}

void eng::ObjectManager::refresh()
{
	m_objects.erase(
		std::remove_if(std::begin(m_objects), std::end(m_objects),
			[](const std::unique_ptr<Object>& objects) { return !objects->getIsActive(); }
		),// remove if
		std::end(m_objects)
	); // erase
}

void eng::Object::Update()
{
	for (uint32_t i = 0; i < m_components.size(); i++) {
		m_components[i]->Update();
		m_components[i]->Draw();
	}
}

void eng::Object::Start()
{
	for (uint32_t i = 0; i < m_components.size(); i++) {
		m_components[i]->Start();
	}
}
void eng::Object::Draw()
{
	for (uint32_t i = 0; i < m_components.size(); i++) {
	}
}

void eng::Object::LightUpdate()
{
	for (int i = 0; i < m_components.size(); i++) {m_components[i]->LightUpdate();}
}

void eng::Object::FixedUpdate()
{
	for (int i = 0; i < m_components.size(); i++) m_components[i]->FixedUpdate();
}

void eng::Object::destroy() { isActive = false; manager->refresh(); }


bool eng::Component::isParentInWindowVeiw() const {
		eng::Postion * p = &Parent->getComponent<eng::Postion>();
		return(0 < p->getPostion().x + p->getSize().x &&
			Parent->window->getSize().x > p->getPostion().x &&
			0 < p->getPostion().y + p->getSize().y &&
			Parent->window->getSize().y > p->getPostion().y
			);
}

