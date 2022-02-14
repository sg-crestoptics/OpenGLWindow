#include <iostream>
#include "GL\glew.h"
#include "GLFW\glfw3.h"

void init(GLFWwindow* window)
{

}

void display(GLFWwindow* window, double currentTime)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{

	//initializing glfw
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(600, 600, "Simple App", NULL, NULL);
	glfwMakeContextCurrent(window);

	//initializing glew
	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);

	glfwSwapInterval(1);
	init(window);

	//rendering the frame buffer to the window
	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//destroying glfw
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}