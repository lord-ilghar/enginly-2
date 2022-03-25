#pragma once
#include <ctime>
#include <stdlib.h>

namespace eng{ 
	class Rand {
	public:
		static int randInt(int min, int max) {
			return (min + (rand() % max));
		}
		static float random() {
			return (float)rand() / (float)RAND_MAX;
		}
	};   
};
 
