#include "../eng/Input.h"

int8_t eng::Input::getAxis(Axis axie)
{
	switch (axie)
	{
	case eng::Input::Axis::Horizontal:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return 1;
		break;
	case eng::Input::Axis::Vertical:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up))return -1;		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) return 1;
		break;
	default:
		return 0;
		break;
	}
}

bool eng::Input::KeyPress(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}
