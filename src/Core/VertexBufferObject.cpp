#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject() {
	glGenBuffers(1, &ID);
}

void VertexBufferObject::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBufferObject::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::CopyVertices(GLfloat* vertices, size_t size) {
	glBufferData(GL_ARRAY_BUFFER, size*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
}

void VertexBufferObject::Delete() {
	glDeleteBuffers(1, &ID);
}