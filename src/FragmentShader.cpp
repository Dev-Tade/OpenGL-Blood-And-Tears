#include <iostream>
#include "FragmentShader.hpp"

FragmentShader::FragmentShader(const char* fragmentShaderCode) {
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &fragmentShaderCode, NULL);
    glCompileShader(shader);
}

void FragmentShader::Delete() {
    glDeleteShader(shader);
}

void FragmentShader::CompileErrors() {
	GLint hasCompiled;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
	if (hasCompiled == GL_FALSE) {
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADERS::FRAGMENT" << "\n" << infoLog << std::endl;
	}
}