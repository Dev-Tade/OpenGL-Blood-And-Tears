#ifndef FRAGMENT_SHADER_H
#define FRAGMENT_SHADER_H

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
