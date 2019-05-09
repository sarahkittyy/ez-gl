#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <stdexcept>

namespace ez
{

class Shader
{
public:
	Shader();

	static void useDefault();

private:
	static GLuint SHADER;

	static const char* vert;
	static const char* frag;
};

}