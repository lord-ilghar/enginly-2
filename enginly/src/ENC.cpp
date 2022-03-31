#include "../eng/ENC.h"
#include "../debugTools/debug.h"


void eng::ObjectManer::Update()
{
	for (auto& i : m_objects) {
		i->Update();
	}
}


void eng::ObjectManer::Start()
{
	for (auto& i : m_objects) {
		i->Start();
	}
}

void eng::ObjectManer::Draw()
{
	for (auto& i : m_objects) {
		i->Draw();
	}
}

void eng::Object::Update()
{
	for (auto& i : m_components) {
		i->Update();
		/*if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Update();
		}*/
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
	for (auto& i : m_components) {
		i->Update();
		/*if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Draw();
		}*/
	}
}