#pragma once

namespace ez
{

template <typename T>
class Vec3;

/**
 * @brief A two dimensional vector.
 * 
 * @tparam T A scalar/numerical type.
 */
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
	 * @brief Construct a new Vec2 object from a Vec3 object
	 * 
	 * @tparam V A type castable to T
	 * @param other The other vector
	 */
	template <typename V>
	Vec2(Vec3<V> other)
		: x(other.x),
		  y(other.y)
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

/**
 * @brief A three dimensional vector.
 * 
 * @tparam T A scalar/numerical type.
 */
template <typename T>
class Vec3
{
public:
	/**
	 * @brief Construct a new Vec 3 object
	 * 
	 */
	Vec3()
	{
	}

	/**
	 * @brief Construct a new Vec 3 object
	 * 
	 * @param x The x component
	 * @param y The y component
	 * @param z The z component
	 */
	Vec3(T x, T y, T z)
		: x(x),
		  y(y),
		  z(z)
	{
	}

	/**
	 * @brief Construct a new Vec3 object from a Vec2 object.
	 * 
	 * @tparam V A type convertable to type T
	 * @param other The Vec2 to convert from.
	 */
	template <typename V>
	Vec3(Vec2<V> other)
		: x(other.x),
		  y(other.y),
		  z(0)
	{
	}

	/**
	 * @brief Scale the vector by some scalar c
	 * 
	 * @tparam Scalar Type such that Scalar * T is defined.
	 * @param c The scalar to multiply x, y, and z by
	 * @return Vec3 the resulting vector
	 */
	template <typename Scalar>
	Vec3 operator*(const Scalar& c)
	{
		//Declare a new vector
		Vec3<T> res(*this);
		//Multiply the components.
		res.x *= c;
		res.y *= c;
		res.z *= c;
		return res;
	}

	/**
	 * @brief The vector's X component
	 * 
	 */
	T x;

	/**
	 * @brief The vector's Y component
	 * 
	 */
	T y;

	/**
	 * @brief The vector's Z component
	 * 
	 */
	T z;
};

}