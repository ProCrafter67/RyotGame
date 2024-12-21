#include "mesh.h"

Mesh::Mesh(float vertices[], int indices[], const char* object_name)
{
	std::string VertFileName = object_name;
	std::string FragFileName = object_name;
	VertFileName += "_vert.txt";
	FragFileName += "_frag.txt";

	_shader = new Shader(VertFileName.c_str(), FragFileName.c_str());

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::Render(GLenum mode, int vertices, const GLvoid* offset)
{
	_shader->Use();
	glBindVertexArray(_vao);
	glDrawElements(mode, vertices, GL_UNSIGNED_INT, offset);
	glBindVertexArray(0);
}

void Mesh::CleanUp()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_ebo);
	_shader->CleanUp();
}