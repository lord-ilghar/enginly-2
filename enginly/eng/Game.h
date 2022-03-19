#pragma once
#define __DEBUG__
#define rainsAmount 300
#include <cstdint>
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "../eng/Vector.h"
#include "../eng/ENC.h"

#include <vector>

namespace eng {
	class Game {
	private:
		sf::RectangleShape rains[rainsAmount];
		uint16_t m_windowW, m_windowH;
		std::string m_title;
		sf::RenderWindow* m_window;
		ObjectManer* m_manger;

		void Update();
		void Start();
		void Init();
		// User vars:
		eng::Vec2i vlocity;
	public:
		Game(uint16_t windowW, uint16_t windowH , std::string title) : m_windowH(windowH), m_windowW(windowW) , m_title(title) , m_window(nullptr) , m_manger(nullptr){
			Init();
		}
		sf::RenderWindow& getWindow() { return *m_window; }
		void run(uint8_t fpsLimit);
		ObjectManer* getmanger() const { return m_manger; }
	};
};