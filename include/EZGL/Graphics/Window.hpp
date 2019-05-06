#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <stdexcept>
#include <string>

namespace ez
{

class Window
{
public:
	/**
	 * @brief Construct the window.
	 * 
	 * @param width The window width
	 * @param height The window height
	 * @param title The window title
	 */
	Window(unsigned width, unsigned height, std::string title);

	/**
	 * @return true If the window hasn't been closed.
	 * @return false If the window is closed.
	 */
	bool isOpen();

	/**
	 * @brief Close the window.
	 * 
	 */
	void close();

	/**
	 * @brief Clear the window.
	 * 
	 */
	void clear();

	/**
	 * @brief Display the window, after having cleared and drawn to it.
	 * 
	 */
	void display();

private:
	/**
	 * @brief The GLFW window.
	 * 
	 */
	GLFWwindow* mWindow;

	/**
	 * @brief The window width
	 * 
	 */
	unsigned mWidth;

	/**
	 * @brief The window height
	 * 
	 */
	unsigned mHeight;

	/**
	 * @brief The window title.
	 * 
	 */
	std::string mTitle;
};

}