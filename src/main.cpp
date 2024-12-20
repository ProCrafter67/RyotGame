#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define width 800
#define height 600
#define title "Ryot Game"
#define error(comment) std::cerr << "{ERROR}\t" << comment << std::endl;

void set_bgcolor(int red, int green, int blue)
{
	if ((red > 255) || (red < 0) || (green > 255) || (green < 0) || (blue > 255) || (blue < 0)) {
		error("Could not set background color");
	} else {
		glClearColor(
			(float) (red / 255),
			(float) (green / 255),
			(float) (blue / 255),
			1.0f
		);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (window == NULL)
	{
		error("Could not load GLFWwindow");
		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window);

	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		error("Could not load GLAD");
		glfwTerminate();

		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		// Rendering
		{
			set_bgcolor(19, 112, 212);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}