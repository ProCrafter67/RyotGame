#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600
#define TITLE "Ryot Game"
#define error(comment) std::cerr << "{ERROR}\t" << comment << std::endl;

const char* vertexShaderSrc = "#version 330 core\n"
"layout (location = 0) in vec3 pos;\n\n"
"void main()\n"
"{\n"
"gl_Position = vec4(pos, 1.0);\n"
"}\0";

const char* fragmentShaderSrc = "#version 330 core\n\n"
"void main()\n"
"{\n"
"gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\0";

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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		error("Could not load GLAD");
		glfwTerminate();

		return -1;
	}

	// A Triangle

	// Shader Creation
	unsigned int program, vertexShader, fragmentShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		error(infoLog);
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		error(infoLog);
	}

	program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		error(infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Vertex Creation
	float vertices[] = {
		-0.5f,-0.5f, 0.0f,
		 0.0f, 0.5f, 0.0f,
		 0.5f,-0.5f, 0.0f
	};

	unsigned int VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		// Rendering
		{
			glClearColor(0.98823529411f, 0.7294117647f, 0.01176470588f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(program);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(program);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}