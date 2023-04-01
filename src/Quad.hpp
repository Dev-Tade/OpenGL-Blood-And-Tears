#ifndef QUAD_HPP
#define QUAD_HPP

#include "Engine.h"
#include <vector>

class Quad : public Node {
private:
    size_t verticesLenght;
    size_t indicesLenght;
    GLfloat* vertices;
    GLuint* indices;

    VertexArrayObject VAO;
    VertexBufferObject VBO;
    ElementBufferObject EBO;
public:
    Quad(const std::vector<GLfloat>& vertices, const std::vector<GLuint>& indices) : Node() {
        verticesLenght = vertices.size();
        indicesLenght = indices.size();

        this->vertices = new GLfloat[verticesLenght];
        std::copy(vertices.begin(), vertices.end(), this->vertices);

        this->indices = new GLuint[indicesLenght];
        std::copy(indices.begin(), indices.end(), this->indices);

        VAO.Bind();
        VBO.Bind();
        EBO.Bind();

        VBO.CopyVertices(this->vertices, this->verticesLenght);
        EBO.CopyIndices(this->indices, this->indicesLenght);

        VertexAttribute pos3D(GL_FALSE, 0, 3, 6, 0);
        pos3D.Enable();

        VertexAttribute color3(GL_FALSE, 1, 3, 6, 3);
        color3.Enable();

        VBO.Unbind();
        VAO.Unbind();

        OnLoad();
    }

    void OnLoad() override {
        std::cout << "New Quad" << std::endl;
    }

    void Draw() override {
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void Delete() override {
        VAO.Delete();
        VBO.Delete();
        EBO.Delete();
        delete this->vertices;
        delete this->indices;
    }
};

#endif // !QUAD_HPP