#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600
#define TITLE "Ryot Game"
#define error(comment) std::cerr << "{ERROR}\t" << comment << std::endl;

const char* vertexShaderSrc = "";
const char* fragmentShaderSrc = "";

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);

	if (window == NULL)
	{
		error("Could not load GLFWwindow");
		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		error("Could not load GLAD");
		glfwTerminate();

		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// A Triangle

	unsigned int program, vertexShader, fragmentShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSrc, nullptr);

	float vertices[] = {
		-0.5f,-0.5f, 0.0f,
		 0.0f, 0.5f, 0.0f,
		 0.5f,-0.5f, 0.0f
	};

	unsigned int VAO, VBO;

	while (!glfwWindowShouldClose(window))
	{
		// Rendering
		{
			glClearColor(0.98823529411f, 0.7294117647f, 0.01176470588f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}