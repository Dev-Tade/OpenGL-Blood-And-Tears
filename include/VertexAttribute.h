#ifndef VERTEX_ATTRIBUTE_H
#define VERTEX_ATTRIBUTE_H

#include <glad/glad.h>

class VertexAttribute {
	private:
		GLuint __idx;
	public:
		VertexAttribute(GLboolean normalize, GLuint index, GLint size, GLsizei stride, GLuint start);
		void Enable();
		void Disable();
};

#endif