#include "game_module.h"

void GameModule::LoadGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "{ERROR}\tCould not load GLAD" << std::endl;
	}
}

void GameModule::RenderColor(float red, float green, float blue)
{
	glClearColor(red, green, blue, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GameModule::Enable(GLenum cap)
{
	glEnable(cap);
}

void GameModule::Terminate()
{
	glfwTerminate();
}