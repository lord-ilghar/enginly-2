#include "../eng/ENC.h"
#include "../debugTools/debug.h"


void ObjectManer::Update()
{
	for (auto& i : m_objects) {
		i->Update();
	}
}


void ObjectManer::Start()
{
	for (auto& i : m_objects) {
		i->Start();
	}
}

void ObjectManer::Draw()
{
	for (auto& i : m_objects) {
		i->Draw();
	}
}

void Object::Update()
{
	for (uint32_t i = 0; i < MaxComponents; i++) {
		if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Update();
		}
		else break;
	}
}

void Object::Start()
{
	for (uint32_t i = 0; i < MaxComponents; i++) {
		if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Start();
		}
		else break;
	}
}
void Object::Draw()
{
	for (uint32_t i = 0; i < MaxComponents; i++) {
		if (m_componentCheck[i] == true) {
			m_componentsArray[i]->Draw();
		}
		else break;
	}
}