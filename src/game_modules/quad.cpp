#include "quad.h"

Quad::Quad()
{
	float vertices[] = {
		-0.5f,-0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		 0.5f, 0.5f, 0.0f,
		 0.5f,-0.5f, 0.0f
	};
	int indices[] = {
		0, 1, 2,
		0, 3, 2
	};
	_mesh = new Mesh(vertices, indices, "quad");
}

Quad::~Quad()
{
	_mesh->CleanUp();
}

void Quad::Render()
{
	_mesh->Render(GL_TRIANGLES, 6, 0);
}