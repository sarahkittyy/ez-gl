#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace ez
{

/**
 * @brief A class representing an RGBA color.
 * 
 */
class Color
{
public:
	/**
	 * @brief Construct a new Color
	 * 
	 * @param r Red
	 * @param g Gree
	 * @param b Blue
	 * @param a Alpha
	 */
	Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);

	/**
	 * @brief The red component
	 * 
	 */
	unsigned char r;

	/**
	 * @brief The green component
	 * 
	 */
	unsigned char g;

	/**
	 * @brief The blue component
	 * 
	 */
	unsigned char b;

	/**
	 * @brief The alpha component
	 * 
	 */
	unsigned char a;
};

}