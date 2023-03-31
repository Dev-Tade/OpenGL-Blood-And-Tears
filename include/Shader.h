#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include "VertexShader.h"
#include "FragmentShader.h"

class Shader {
	private:
		GLuint shader;
		void LinkErrors();
	public:
		Shader(VertexShader vertex, FragmentShader fragment);
		void SetBool(const std::string& name, bool value);
		void SetInt(const std::string& name, int value);
		void SetFloat(const std::string& name, float value);
		void Delete();
		void Activate();
		void Deactivate();
};

#endif // !SHADER_H