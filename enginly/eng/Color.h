#pragma once
#include "../debugTools/debug.h"

namespace eng {
	struct RGB {
		static int normalize(int number) {
			return std::min(std::max(number, 0), 255);
		}
		RGB(uint8_t red, uint8_t green, uint8_t blue) {
			r = normalize((int)red);
			b = normalize((int)green);
			g = normalize((int)blue);
		}
		uint8_t r, g, b;
	};
};