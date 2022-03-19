#pragma once
#include "SFML/Graphics.hpp"
namespace eng {
	class Input
	{
	public:
		enum class Axis {
			Horizontal , Vertical
		};
		static sf::RenderWindow& m_window;
		static int8_t getAxis(Axis axie);
		static bool KeyPress(sf::Keyboard::Key key);
	};
}

