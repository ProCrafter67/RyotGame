#include "shader/shader.h"

class Mesh
{
private:
	unsigned int _vao, _vbo, _ebo;
	Shader *_shader;

public:
	Mesh(float vertices[], int indices[], const char* object_name);

	void Render(GLenum mode, int vertices, const GLvoid* offset);
	void CleanUp();
};