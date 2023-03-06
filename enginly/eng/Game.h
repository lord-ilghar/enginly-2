#pragma once
#define __DEBUG__
#include <cstdint>
#include <functional>
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "../eng/Vector.h"
#include "../eng/ECS.h"
#include "Color.h"
#include "Input.h"
#include "Rand.h"
#include "Vector.h"
#include <vector>

namespace eng {
	std::vector<std::string> split_str(const std::string& str, const char delim);
	class Game {
	private:
		uint16_t m_windowW, m_windowH;
		std::string m_title;
		sf::RenderWindow* m_window;
		ObjectManager* m_manger;
		float_t deltaTime = 0;
		std::function<void(sf::RenderWindow*)> m_outSideDraw;
		std::function<void()> m_outSideStart;
		void Update();
		void Start();
		void Init();
		bool OutSideLoop = false;
	public:
		void enableAdditionalFeatures(bool enable) {
			OutSideLoop = enable;
			m_outSideDraw = [](sf::RenderWindow* rc) {};
			m_outSideStart = []() {};
		}
		//TODO: RENAME THEAS 
		void setAdditionalDraw(std::function<void(sf::RenderWindow*)> outSideDraw) {
			this->m_outSideDraw = outSideDraw;
		}
		void setAdditionalStart(std::function<void()> outSideStart) {
			m_outSideStart = outSideStart;
		}

		Game(uint16_t windowW, uint16_t windowH, std::string title) : m_windowH(windowH), m_windowW(windowW), m_title(title), m_window(nullptr),
			m_manger(nullptr), m_outSideDraw(), m_outSideStart() {
			Init();
		}
		sf::RenderWindow& getWindow() { return *m_window; }
		void run();
		void setFPSLimit(uint8_t fpsLimit) {getWindow().setFramerateLimit(fpsLimit);}
		ObjectManager* getmanger() const { return m_manger; }
		~Game();
	};
};