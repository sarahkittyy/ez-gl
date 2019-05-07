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
	Color(float r = 0, float g = 0, float b = 0, float a = 255);

	/**
	 * @brief Get a color where the r g b a components are normalized between 0 & 1
	 * 
	 * @return Color The normalized color. 
	 */
	Color normalize();

	/**
	 * @brief The red component
	 * 
	 */
	float r;

	/**
	 * @brief The green component
	 * 
	 */
	float g;

	/**
	 * @brief The blue component
	 * 
	 */
	float b;

	/**
	 * @brief The alpha component
	 * 
	 */
	float a;
};

}