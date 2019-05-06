#pragma once

namespace ez
{

template <typename T>
class Vec2
{
public:
	/**
	 * @brief Default constructor.
	 * 
	 */
	Vec2()
	{
	}

	/**
	 * @brief Construct a vec2 from the components
	 * 
	 * @param x The x component
	 * @param y The y component
	 */
	Vec2(T x, T y)
		: x(x),
		  y(y)
	{
	}

	/**
	 * @brief Scale the vector by some scalar c
	 * 
	 * @tparam Scalar Type such that Scalar * T is defined.
	 * @param c The scalar to multiply x and y by
	 * @return Vec2 the resulting vector
	 */
	template <typename Scalar>
	Vec2 operator*(const Scalar& c)
	{
		//Declare a new vector
		Vec2<T> res(*this);
		//Multiply the components.
		res.x *= c;
		res.y *= c;
		return res;
	}

	/**
	 * @brief The X component of the vector.
	 * 
	 */
	T x;

	/**
	 * @brief The Y component of the vector.
	 * 
	 */
	T y;
};

template <typename T>
class Vec3
{
};

}