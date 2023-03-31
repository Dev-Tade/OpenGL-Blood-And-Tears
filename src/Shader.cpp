#include <iostream>
#include "Shader.h"

Shader::Shader(VertexShader vertex, FragmentShader fragment) {
    shader = glCreateProgram();
    glAttachShader(shader, vertex.shader);
    glAttachShader(shader, fragment.shader);
    glLinkProgram(shader);

    vertex.Delete();
    fragment.Delete();
}

void Shader::SetBool(const std::string& name, bool value) {
    glUniform1i(glGetUniformLocation(shader, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(shader, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) {
    glUniform1f(glGetUniformLocation(shader, name.c_str()), value);
}

void Shader::Activate() {
    glUseProgram(shader);
}

void Shader::Deactivate() {
    glUseProgram(0);
}

void Shader::Delete() {
    glDeleteProgram(shader);
}

void Shader::LinkErrors() {
    GLint hasCompiled;
    char infoLog[512];
    glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE) {
        glGetProgramInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::SHADERS::FINAL" << "\n" << infoLog << std::endl;
    }
}