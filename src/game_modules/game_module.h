#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GameModule
{
public:
	void LoadGLAD();
	void RenderColor(float red, float green, float blue);
	void Enable(GLenum cap);

	void Terminate();
};