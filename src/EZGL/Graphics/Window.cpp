#include "EZGL/Graphics/Window.hpp"

namespace ez
{

Window::Window(unsigned width, unsigned height, std::string title)
{
	//Initialize the settings
	mWidth  = width;
	mHeight = height;
	mTitle  = title;

	//Set glew to experimental
	glewExperimental = true;

	//Init GLEW
	if (!glfwInit())
	{
		glfwTerminate();
		throw std::runtime_error("Could not init glfw!");
	}

	//Init the
	mWindow = glfwCreateWindow(mWidth, mHeight, title.c_str(), nullptr, nullptr);
	if (mWindow == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Could not open glfw window");
	}

	//Set the window as current.
	glfwMakeContextCurrent(mWindow);
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		throw std::runtime_error("Could not init glew!");
	}
}

bool Window::isOpen()
{
	return glfwWindowShouldClose(mWindow) == GLFW_FALSE;
}

void Window::close()
{
	glfwSetWindowShouldClose(mWindow, GLFW_TRUE);
	glfwTerminate();
}

void Window::clear()
{
	//Clear the color and depth bits
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	//Poll events
	glfwPollEvents();
}

void Window::display()
{
	//Swap & display
	glfwSwapBuffers(mWindow);
}

}