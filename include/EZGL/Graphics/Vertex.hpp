#pragma once

#include "EZGL/Graphics/Color.hpp"
#include "EZGL/Utility/Vector.hpp"

namespace ez
{

/**
 * @brief A generic vertex class.
 * 
 */
class Vertex
{
public:
	/**
	 * @brief Construct the vertex with the given position and color.
	 * 
	 * @param pos The vertex position.
	 * @param col The vertex color.
	 */
	Vertex(Vec3<float> pos = Vec3<float>(0, 0, 0), Color col = Color(0, 0, 0, 255));

	/**
	 * @brief The vertex position.
	 * 
	 */
	Vec3<float> position;

	/**
	 * @brief The vertex color.
	 * 
	 */
	Color color;
};

}