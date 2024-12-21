#include <iostream>
#include <GLFW/glfw3.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define DEFAULT_TITLE "Ryot Game"

class Window
{
private:
	GLFWwindow* _window;
	int _width;
	int _height;
	const char* _title;

	bool _maximized, _resizable;

public:
	Window(bool is_fullscreen = false, bool maximized = true, bool resizable = true)
	{
		_width = DEFAULT_WIDTH;
		_height = DEFAULT_HEIGHT;
		_title = DEFAULT_TITLE;

		_maximized = maximized;
		_resizable = resizable;

		glfwInit();

		glfwWindowHint(GLFW_MAXIMIZED, maximized ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

		_window = glfwCreateWindow(
			_width, 
			_height,
			_title,
			is_fullscreen ? glfwGetPrimaryMonitor() : nullptr,
			nullptr
		);

		if (_window == NULL)
		{
			std::cerr << "{ERROR}\tCould not create window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(_window);
	}

	int ShouldClose()
	{
		return glfwWindowShouldClose(_window);
	}

	void Refresh()
	{
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}

	void SetFramebufferSizeCallback(GLFWframebuffersizefun callback)
	{
		glfwSetFramebufferSizeCallback(_window, callback);
	}
};