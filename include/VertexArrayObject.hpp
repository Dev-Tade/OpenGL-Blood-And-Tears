#ifndef VAO_HPP
#define VAO_HPP

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
