#pragma once
#include "SFML/Graphics.hpp"
namespace eng {
	class Input
	{
	public:
		enum class Axis {
			Horizontal , Vertical
		};
		using MouseButton = sf::Mouse::Button;

		static sf::RenderWindow& m_window;
		static int8_t getAxis(Axis axie);
		static bool KeyPress(sf::Keyboard::Key key);
		static bool MousePress(MouseButton button);
	};
}

