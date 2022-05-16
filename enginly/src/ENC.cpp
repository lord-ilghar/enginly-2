#include "../eng/ENC.h"
#include "../debugTools/debug.h"


void eng::ObjectManer::Update(float_t deltaTime)
{
	ImGui::Begin("Manger Props");

	ImGui::Text("Object amount: %d", m_objects.size());

	ImGui::End();


	for (int i = 0; i < m_objects.size(); i++) {
		eng::Vec2f postion = m_objects[i]->getComponent<Postion>().getPostion();
		eng::Vec2f size = m_objects[i]->getComponent<Postion>().getSize();
		if (0 < postion.x + size.x &&
			m_simulationDistance.x + m_window->getSize().x > postion.x &&
			0 < postion.y + size.y && 
			m_simulationDistance.y + m_window->getSize().y > postion.y
			) {
			m_objects[i]->setDeltaTime(deltaTime);
			m_objects[i]->Update();
		}
	}
}


void eng::ObjectManer::Start()
{
	for (int i = 0; i < m_objects.size(); i++) {
		m_objects[i]->Start();
	}
}

void eng::ObjectManer::Draw()
{
	for (int i = 0; i < m_objects.size(); i++) {
		eng::Vec2f postion = m_objects[i]->getComponent<Postion>().getPostion();
		eng::Vec2f size = m_objects[i]->getComponent<Postion>().getSize();
		if (0 < postion.x + size.x &&
			m_window->getSize().x > postion.x &&
			0 < postion.y + size.y &&
			m_window->getSize().y > postion.y
			) {
		m_objects[i]->Draw();
		}
	}
}

void eng::Object::Update()
{
	for (uint32_t i = 0; i < m_components.size(); i++) {
		m_components[i]->Update();
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
		m_components[i]->Draw();
	}
}

void eng::Object::destroy() { isActive = false; manager->refresh(); }
