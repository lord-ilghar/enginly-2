#pragma once
namespace eng {
template <typename T>
	struct Vector2
	{
		T x, y;
		Vector2(T x, T y)
			:x(x), y(y) {}		
		Vector2()
			:x(0), y(0) {}
		static Vector2<T> Up() {
			return Vector2<T>(0, 1);
		}
		static Vector2<T> Down() {
			return Vector2<T>(0, -1);
		}
		static Vector2<T> Left() {
			return Vector2<T>(-1, 0);
		}
		static Vector2<T> Right() {
			return Vector2<T>(1, 0);
		}
	};
typedef eng::Vector2<float> Vec2f;
typedef eng::Vector2<int> Vec2i;
}
