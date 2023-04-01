#include "ElementBufferObject.hpp"

ElementBufferObject::ElementBufferObject() {
	glGenBuffers(1, &ID);
}

void ElementBufferObject::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void ElementBufferObject::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBufferObject::CopyIndices(GLuint indices[], size_t size) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size*sizeof(GLuint), indices, GL_STATIC_DRAW);
}

void ElementBufferObject::Delete() {
	glDeleteBuffers(1, &ID);
}