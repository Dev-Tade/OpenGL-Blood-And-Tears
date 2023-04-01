#include <iostream>
#include "VertexShader.hpp"

VertexShader::VertexShader(const char* vertexShaderCode) {
	shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader, 1, &vertexShaderCode, NULL);
	glCompileShader(shader);
}

void VertexShader::Delete() {
	glDeleteShader(shader);
}

void VertexShader::CompileErrors() {
	GLint hasCompiled;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
	if (hasCompiled == GL_FALSE) {
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADERS::VERTEX" << "\n" << infoLog << std::endl;
	}
}