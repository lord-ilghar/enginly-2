#pragma once
#include <cmath>
#include "Rand.h"
#include <math.h>

#define PI 3.14159265

namespace eng {
template <typename T>
struct Vector2
{
public:
	T x, y;
	Vector2(T x, T y)
		:x(x), y(y) {}
	Vector2()
		:x(0), y(0) {}

	// operator Overloads:
	Vector2<T> operator + (Vector2<T> const& c2)
	{
		return Vector2<T>(x + c2.x, y + c2.y);
	}

	Vector2<T> operator * (Vector2<T> const& c2)
	{
		return Vector2<T>(x * c2.x, y * c2.y);
	}
	Vector2<T> operator % (Vector2<T> const& c2)
	{
		return Vector2<T>(x % c2.x, y % c2.y);
	}
	Vector2<T> operator - (Vector2<T> const& c2)
	{
		return Vector2<T>(x - c2.x, y - c2.y);
	}
	Vector2<T>& operator -= (Vector2<T> const& c2)
	{
		this->x -= c2.x;
		this->y -= c2.y;
		return *this;
	}
	Vector2<T>& operator += (Vector2<T> const& c2)
	{
		this->x += c2.x;
		this->y += c2.y;
		return *this;
	}
	Vector2<T>& operator *= (Vector2<T> const& c2)
	{
		this->x *= c2.x;
		this->y *= c2.y;
		return *this;
	}
	Vector2<T>& operator /= (Vector2<T> const& c2)
	{
		this->x /= c2.x;
		this->y /= c2.y;
		return *this;
	}


	bool operator == (Vector2<T> const& c2)
	{
		return (x == c2.x && y == c2.y);
	}
	bool operator > (Vector2<T> const& c2)
	{
		return (x > c2.x && y > c2.y);
	}
	bool operator < (Vector2<T> const& c2)
	{
		return (x < c2.x && y < c2.y);
	}

	bool operator >= (Vector2<T> const& c2)
	{
		return (x >= c2.x && y >= c2.y);
	}

	bool operator <= (Vector2<T> const& c2)
	{
		return (x <= c2.x && y <= c2.y);
	}

	Vector2<T> operator * (T c)
	{
		return Vector2<T>(x * c, y * c);
	}
	Vector2<T> operator - (T c)
	{
		return Vector2<T>(x - c, y - c);
	}
	Vector2<T> operator / (T c)
	{
		return Vector2<T>(x / c, y / c);
	}
	Vector2<T> operator + (T c)
	{
		return Vector2<T>(x + c, y + c);
	}

	// static functions
	static Vector2<T> Up() { return Vector2<T>(0, 1); }
	static Vector2<T> Down() { return Vector2<T>(0, -1); }
	static Vector2<T> Left() { return Vector2<T>(-1, 0); }
	static Vector2<T> Right() { return Vector2<T>(1, 0); }
	static Vector2<float> RandomUnitVector() { return Vector2<float>(eng::Rand::random(), eng::Rand::random()); }

	//static T magnitude(Vector2<T> vector) { return std::sqrt(vector.x * vector.x + vector.y * vector.y); }
	//static T sqMagnitude(Vector2<T> vector) { return (vector.x * vector.x + vector.y * vector.y); }
	//static T distance(Vector2<T> Vector , Vector2<T> otherVector) { return magnitude(otherVector - Vector); }
	
	// utility functions :
	T magnitude() { return std::sqrt(x * x + y * y); }
	T distance(Vector2<T> otherVector) { return magnitude(otherVector - *this); }
	T sqMagnitude() { return (x * x + y * y); }
	T heading() { return atan2(x, y) * 180 / PI; }
	Vector2<T> round() { return Vector2<T>(std::round(x), std::round(y)); }
	Vector2<T> floor() { return Vector2<T>(std::floor(x), std::floor(y)); }
	void normalize() {
		T mag = magnitude();
		if (mag != 0) *this = ((*this) * (1 / mag));
	}
	std::string toString() {return " X: " + std::to_string(x) + " - " + "Y: " + std::to_string(y);}
	void set(T x, T y) { this->x = x; this->y = y; }
	void set(Vector2<T> newVector) { *this = newVector; }
	void setMag(T m) {
		normalize();
		*this = (*this * m);
	}
	void setHeading(int deg){
		T m = magnitude();
		x = m * std::cos(deg);
		y = m * std::sin(deg);
	}
	void limit(T l) { this->x = std::min(this->x, l); }
};
typedef eng::Vector2<float> Vec2f;
typedef eng::Vector2<int> Vec2i;
}
