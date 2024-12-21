#include "shader.h"

Shader::Shader(const char* vertex_file_name, const char* fragment_file_name)
{
	std::string ShaderFolderPath = "src\\game_modules\\mesh\\shader\\shader codes\\";
	std::string VertexPath = ShaderFolderPath + vertex_file_name;
	std::string FragmentPath = ShaderFolderPath + fragment_file_name;

	const char* VertCode = "#version 330 core\n"
		"layout (location = 0) in vec3 Pos;\n"
		"void main()\n"
	    "{\n"
		"   gl_Position = vec4(Pos.x, Pos.y, Pos.z, 1.0);\n"
		"}\0";
	const char* FragCode = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
	    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	unsigned int VertShader, FragShader;

	VertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertShader, 1, &VertCode, NULL);
	glCompileShader(VertShader);

	int success;
	char infoLog[512];
	glGetShaderiv(VertShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(VertShader, 512, NULL, infoLog);
		std::cerr << "{ERROR}\tCould not compile vertex shader : " << infoLog << std::endl;
	}

	FragShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(FragShader, 1, &FragCode, NULL);
	glCompileShader(FragShader);

	glGetShaderiv(FragShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(FragShader, 512, NULL, infoLog);
		std::cerr << "{ERROR}\tCould not compile fragment shader : " << infoLog << std::endl;
	}

	_program = glCreateProgram();

	glAttachShader(_program, VertShader);
	glAttachShader(_program, FragShader);
	glLinkProgram(_program);

	glGetProgramiv(_program, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		std::cerr << "{ERROR}\tCould not link program : " << infoLog << std::endl;
	}
	glDeleteShader(VertShader);
	glDeleteShader(FragShader);
}

const char* Shader::LoadFile(const char* file_path)
{
	std::string code;
	std::ifstream file;
	
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		file.open(file_path);
		std::stringstream stream;

		stream << file.rdbuf();
		file.close();

		code = stream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cerr << "Could not read file : " << e.what() << std::endl;
	}

	std::cout << code.c_str() << std::endl;
	
	return code.c_str();
}

void Shader::Use()
{
	glUseProgram(_program);
}

void Shader::SetBool(const char* name, bool value)
{
	glUniform1i(glGetUniformLocation(_program, name), (int)value);
}

void Shader::SetInt(const char* name, int value)
{
	glUniform1i(glGetUniformLocation(_program, name), value);
}

void Shader::SetFloat(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(_program, name), value);
}

void Shader::SetVec2(const char* name, glm::vec2 value)
{
	glUniform2fv(glGetUniformLocation(_program, name), 1, glm::value_ptr(value));
}

void Shader::SetVec3(const char* name, glm::vec3 value)
{
	glUniform3fv(glGetUniformLocation(_program, name), 1, glm::value_ptr(value));
}

void Shader::SetVec4(const char* name, glm::vec4 value)
{
	glUniform4fv(glGetUniformLocation(_program, name), 1, glm::value_ptr(value));
}

void Shader::SetMat2(const char* name, glm::mat2 value)
{
	glUniformMatrix2fv(glGetUniformLocation(_program, name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat3(const char* name, glm::mat3 value)
{
	glUniformMatrix3fv(glGetUniformLocation(_program, name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat4(const char* name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(_program, name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::CleanUp()
{
	glDeleteProgram(_program);
}