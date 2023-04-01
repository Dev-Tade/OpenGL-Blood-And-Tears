#ifndef VERTEX_SHADER_HPP
#define VERTEX_SHADER_HPP

#include <glad/glad.h>

class VertexShader {
	private:
		void CompileErrors();
	public:
		GLuint shader;
		VertexShader(const char* vertexShaderCode);
		void Delete();
};

#endif // !VERTEX_SHADER_H
