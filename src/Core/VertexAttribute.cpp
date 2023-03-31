#include "VertexAttribute.h"

VertexAttribute::VertexAttribute(GLboolean normalize, GLuint index, GLint size, GLsizei stride, GLuint start) {
	__idx = index;
	glVertexAttribPointer(__idx, size, GL_FLOAT, normalize, stride * sizeof(GLfloat), (void*)(start * sizeof(GLfloat)));
}

void VertexAttribute::Enable() {
	glEnableVertexAttribArray(__idx);
}

void VertexAttribute::Disable() {
	glDisableVertexAttribArray(__idx);
}