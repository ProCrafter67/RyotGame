#include "window/window.h"
#include "game_modules/quad.h"

void FramebufferSizeFun(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

class RyotGame
{
private:
	Window* _window;

public:
	RyotGame()
	{
		_window = new Window();
		_window->SetFramebufferSizeCallback(FramebufferSizeFun);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "{ERROR}\tCould not load GLAD" << std::endl;
		}
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
	}

	void Run()
	{
		Quad _quad{};

		while (!_window->ShouldClose())
		{
			// Rendering
			{
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				_quad.Render();
			}

			_window->Refresh();
		}

		glfwTerminate();
	}
};