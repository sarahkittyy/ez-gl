#include "EZGL/Graphics/Shader.hpp"

namespace ez
{

const char* Shader::vert = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

out vec4 Color;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	Color = color;
}
)";


const char* Shader::frag = R"(
#version 330 core
in vec4 Color;

out vec4 FragColor;

void main()
{
    FragColor = Color;
}
)";

GLuint Shader::SHADER;

Shader::Shader()
{
	GLuint VSHADER = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VSHADER, 1, &vert, nullptr);
	glCompileShader(VSHADER);

	GLuint FSHADER = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FSHADER, 1, &frag, nullptr);
	glCompileShader(FSHADER);

	SHADER = glCreateProgram();
	glAttachShader(SHADER, VSHADER);
	glAttachShader(SHADER, FSHADER);
	glLinkProgram(SHADER);

	glValidateProgram(SHADER);
	GLint status;
	glGetProgramiv(SHADER, GL_VALIDATE_STATUS, &status);
	if (status != GL_TRUE)
	{
		throw std::runtime_error("Shader did not load!");
	}

	glDeleteShader(VSHADER);
	glDeleteShader(FSHADER);
}

void Shader::useDefault()
{
	glUseProgram(SHADER);
}

}