#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

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