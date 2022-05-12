#include "../eng/ENC.h"
#include "../debugTools/debug.h"


void eng::ObjectManer::Update(float_t deltaTime)
{
	ImGui::Begin("Manger Props");

	ImGui::Text("Object amount: %d", m_objects.size());

	ImGui::End();


	for (int i = 0; i < m_objects.size(); i++) {
		m_objects[i]->setDeltaTime(deltaTime);
		m_objects[i]->Update();
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
		m_objects[i]->Draw();
	}
}

void eng::Object::Update()
{
	for (uint32_t i = 0; i < MaxComponents; i++) {
		if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Update();
		}
	}
}

void eng::Object::Start()
{
	for (uint32_t i = 0; i < MaxComponents; i++) {
		if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Start();
		}
	}
}
void eng::Object::Draw()
{
	for (uint32_t i = 0; i < MaxComponents; i++) {
		if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Draw();
		}
	}
}