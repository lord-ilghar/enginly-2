#pragma once
#include <ctime>
#include <stdlib.h>
#include "Color.h"

namespace eng{ 
	class Rand {
	public:
		static float random() {return (float)rand() / (float)RAND_MAX;}
		static int Int(int min, int max) {return (min + (rand() % max));}
		static void SetSeed(int seed) {srand(seed);}
		template<typename T>
		static T Find(std::vector<T> list) {return list[randInt(0, list.size())];}
		template<typename T , int size>
		static T Find(std::array<T ,size> list) {return list[randInt(0, size)];}

		template<typename T , int size>
		static T Find(T list[]) {return list[randInt(0, size)];}
		static RGB Color() {return RGB(Int( 0 , 256) , Int(0, 256) , Int(0 , 256));}
	};   
};
 
