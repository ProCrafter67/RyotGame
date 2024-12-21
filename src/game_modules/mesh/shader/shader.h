#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
	unsigned int _program;

	const char* LoadFile(const char* file_path);

public:
	Shader(const char* vertex_file_name, const char* fragment_file_name);
	Shader() = delete;

	void Use();

	void SetBool(const char* name, bool value);
	void SetInt(const char* name, int value);
	void SetFloat(const char* name, float value);

	void SetVec2(const char* name, glm::vec2 value);
	void SetVec3(const char* name, glm::vec3 value);
	void SetVec4(const char* name, glm::vec4 value);

	void SetMat2(const char* name, glm::mat2 value);
	void SetMat3(const char* name, glm::mat3 value);
	void SetMat4(const char* name, glm::mat4 value);

	void CleanUp();
};