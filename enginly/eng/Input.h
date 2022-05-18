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
		using KeyBordButton = sf::Keyboard::Key;


		static sf::RenderWindow& m_window;
		static int8_t getAxis(const eng::Input::Axis axie);
		static bool KeyPress(const eng::Input::KeyBordButton key);
		static bool MousePress(const eng::Input::MouseButton button);
	};
}

