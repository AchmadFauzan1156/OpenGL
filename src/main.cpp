#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "ShaderManager.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    float aspect = (float)width / (float)height;

    if (aspect >= 1.0f)
    {
        glViewport(
            (width - height) / 2,
            0,
            height,
            height
        );
    }
    else
    {
        glViewport(
            0,
            (height - width) / 2,
            width,
            width
        );
    }
}

int main()
{
    if (!glfwInit())
    {
        std::cout << "Gagal inisialisasi GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Kotak", NULL, NULL);
    if (!window)
    {
        std::cout << "Gagal membuat window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return -1;
    }

    ShaderManager::GetInstance()->compileAndLink("shaders/main.vs", "shaders/main.fs");
    unsigned int shaderProgram = ShaderManager::GetInstance()->getShaderProgram();

    float side = 1.0f;
    float height = (std::sqrt(3.0f) / 2.0f) * side;

    float vertices[] = {
        0.0f,-0.5f,0.0f,        1.0f, 0.0f, 0.0f,     0.0f,0.0f,
        0.0f,0.5f,0.0f,         0.0f, 1.0f, 0.0f,     0.0f,1.0f,
        0.5f,-0.5f,0.0f,        0.0f,  0.0f, 1.0f,    1.0f,0.0f,
        0.5f,0.5f,0.0f,         1.0f,  0.0f, 0.0f,    1.0f,1.0f,
    };

    unsigned int indices[] = {
        // index dr 0
        0, 1, 2,   // Segitiga 1
        1, 2, 3,   // Segitiga 2
    };

    GLuint VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*6, (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*6, (GLvoid*)(3*sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        float timeValue = glfwGetTime();
        float colorValue = sin(timeValue) * 0.5f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "colorUniform");
        glUniform4f(vertexColorLocation, 1.0f, colorValue, 1.0f, 1.0f);
        glBindVertexArray(VAO);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    ShaderManager::GetInstance()->destroy();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}