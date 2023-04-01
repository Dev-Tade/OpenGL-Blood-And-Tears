#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine.h"
#include "Quad.hpp"

/*
GLfloat Vertices[] = {
    // positions          // colors           // texture coords
     0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   //1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   //1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   //0.0f, 0.0f,   // bottom left
    -0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   //0.0f, 1.0f    // top left 
};

GLuint Indices[] = {
    0, 1, 3,
    1, 2, 3,
};
*/

std::vector<GLfloat> vertices = {
    // positions          // colors           // texture coords
     0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   //1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   //1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   //0.0f, 0.0f,   // bottom left
    -0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   //0.0f, 1.0f    // top left 
};

std::vector<GLuint> indices = {
    0, 1, 3,
    1, 2, 3,
};

void resizeCallback(GLFWwindow* window, int w, int h);
void inputCallback(GLFWwindow* window);

bool wireframe = false;

int main(int argc, char** argv) {
	std::cout << "Hello World" << std::endl;

    GLFWwindow* window;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cout << "ERROR::GLFW::INIT" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(500, 500, "Hello World", NULL, NULL);
    if (!window) {
        std::cout << "ERROR::GLFW::WINDOW::CREATE" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSize(window, 500, 500);
    glfwShowWindow(window);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, resizeCallback);
    

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "ERROR::GLAD::INIT" << std::endl;
        return -1;
    }

    
    std::string vertexCode = AUX::readShaderFile("./src/Shaders/vertexDefault.glsl");
    std::string fragmentCode = AUX::readShaderFile("./src/Shaders/fragmentDefault.glsl");

    const char* vertexShaderSrc = vertexCode.c_str();
    const char* fragmentShaderSrc = fragmentCode.c_str();

    VertexShader vertex(vertexShaderSrc);
    FragmentShader fragment(fragmentShaderSrc);

    Shader shader(vertex, fragment);
    
    /*
    VertexArrayObject VAO;
    VertexBufferObject VBO;
    ElementBufferObject EBO;

    VAO.Bind();
    VBO.Bind();
    EBO.Bind();

    VBO.CopyVertices(Vertices, ARRSIZE(Vertices));
    EBO.CopyIndices(Indices, ARRSIZE(Indices));

    VertexAttribute pos3D(GL_FALSE, 0, 3, 6, 0);
    pos3D.Enable();
    
    VertexAttribute color3(GL_FALSE, 1, 3, 6, 3);
    color3.Enable();

    VBO.Unbind();
    VAO.Unbind();
    */
    
    Quad testq(vertices, indices);

    shader.Activate();

    static double frameRateLimit = 1.0 / 60.0;
    double lastTime = glfwGetTime(), timer = lastTime;
    double deltaTime = 0, nowTime = 0;
    int frames = 0, updates = 0;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        nowTime = glfwGetTime();
        deltaTime += (nowTime - lastTime) / frameRateLimit;
        lastTime = nowTime;

        while (deltaTime >= 1.0) {
            inputCallback(window);

            updates++;
            deltaTime--;
        }
        
        if (wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
        shader.Activate();

        testq.Draw();
        /*
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        */
        
        frames++;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        
        // - Reset after one second
        if (glfwGetTime() - timer > 1.0) {
            timer++;
            std::cout << "FPS: " << frames << " Updates:" << updates << std::endl;
            updates = 0, frames = 0;
        }
    }

    /*
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
    */
    testq.Delete();

    shader.Delete();

    glfwTerminate();
    return 0;
}

void resizeCallback(GLFWwindow* window, int w, int h) {
    glViewport(0, 0, w, h);
}

void inputCallback(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS)
        wireframe = !wireframe;
}