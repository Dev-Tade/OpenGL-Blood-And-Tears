#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>

class ElementBufferObject {
private:
	GLuint ID;
public:
	ElementBufferObject();

	void Bind();
	void Unbind();
	void CopyIndices(GLuint indices[], size_t size);
	void Delete();
};

#endif // !EBO_H