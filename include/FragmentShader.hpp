#ifndef FRAGMENT_SHADER_HPP
#define FRAGMENT_SHADER_HPP

#include <glad/glad.h>

class FragmentShader {
	private:
		void CompileErrors();
	public:
		GLuint shader;
		FragmentShader(const char* fragmentShaderCode);
		void Delete();
};

#endif // !FRAGMENT_SHADER_H
