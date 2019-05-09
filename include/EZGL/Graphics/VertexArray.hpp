#pragma once

#include "EZGL/Graphics/Color.hpp"
#include "EZGL/Graphics/Shader.hpp"
#include "EZGL/Graphics/Vertex.hpp"
#include "EZGL/Graphics/Window.hpp"
#include "EZGL/Utility/Vector.hpp"

#include <vector>

namespace ez
{

/**
 * @brief The available opengl primitive types for vertex arrays.
 * 
 */
enum Primitive
{
	Points		  = GL_POINTS,
	Lines		  = GL_LINES,
	LineStrip	 = GL_LINE_STRIP,
	LineLoop	  = GL_LINE_LOOP,
	Polygon		  = GL_POLYGON,
	Quads		  = GL_QUADS,
	QuadStrip	 = GL_QUAD_STRIP,
	Triangles	 = GL_TRIANGLES,
	TriangleStrip = GL_TRIANGLE_STRIP,
	TriangleFan   = GL_TRIANGLE_FAN
};

class VertexArray
{
public:
	/**
	 * @brief Construct the vertex array.
	 * 
	 * @param window The window in use.
	 */
	VertexArray(Window* window);

	/**
	 * @brief Push a vertex to the vertex array.
	 * 
	 * @param v The vertex to push.
	 */
	void push(Vertex v);

	void setPrimitiveType(Primitive p);

	void draw();

private:
	/**
	 * @brief The opengl Vertex Buffer Object
	 * 
	 */
	GLuint mVBO;

	/**
	 * @brief The Vertex Array Object
	 * 
	 */
	GLuint mVAO;

	/**
	 * @brief The array primitive type.
	 * 
	 */
	Primitive mPrimitive;

	/**
	 * @brief The main program window.
	 * 
	 */
	Window* mWindow;

	/**
	 * @brief Initialize the vertex array.
	 * 
	 */
	void init();

	/**
	 * @brief The array vertices
	 * 
	 */
	std::vector<Vertex> mVertices;

	/**
	 * @brief The vertices, converted to raw floats. Updated by update().
	 * 
	 */
	std::vector<float> mData;

	/**
	 * @brief Update mData with the content in mVertices.
	 * 
	 */
	void update();

	/**
	 * @brief Update opengl buffers and the array object to match mData
	 * 
	 * @remarks Called by update()
	 * 
	 */
	void updateGL();
};

}