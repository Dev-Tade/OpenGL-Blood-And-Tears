#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>

class VertexBufferObject {
private:
	GLuint ID;
public:
	VertexBufferObject();

	void Bind();
	void Unbind();
	void CopyVertices(GLfloat* vertices, size_t size);
	void Delete();
};

#endif // !VBO_H