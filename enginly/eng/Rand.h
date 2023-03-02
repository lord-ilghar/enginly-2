#pragma once
#include <ctime>
#include <stdlib.h>
#include "Color.h"

namespace eng{ 
	class Rand {
	public:
		static float random() {return (float)rand() / (float)RAND_MAX;}
		static int Int(const int min, const int max) {return (min + (rand() % max));}
		static int Int(const int max) {return ((rand() % max));}
		static void SetSeed(const int seed) {srand(seed);}
		template<typename T>
		static T Find(const std::vector<T>& list) {return list[randInt(list.size())];}
		template<typename T , int size>
		static T Find(const std::array<T ,size>& list) {return list[randInt(size)];}

		template<typename T , int size>
		static T Find(const T list[]) {return list[randInt(size)];}
		static Color::RGB Color() {return Color::RGB(Int(256) , Int(256) , Int(256) , 255);}
	};   
};
 
