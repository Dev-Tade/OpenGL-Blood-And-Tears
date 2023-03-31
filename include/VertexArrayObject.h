#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>

class VertexArrayObject {
	private:
		GLuint ID;
	public:
		VertexArrayObject();
		
		void Bind();
		void Unbind();
		void Delete();
};

#endif // !VAO_H
