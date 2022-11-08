#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <string>
#include <iostream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Cords.hpp"


namespace win
{
    void RunDeffult();
    inline auto RunFunction = RunDeffult;
}


class Window
{
public:
    int Hight = 800;
    int Width = 800;
    void CreateWindow();
    Window();
    GLFWwindow* window;
    void Run();

public:
    void GameEnd();
};

class Shader
{
public:
    Window* WindowVar;
public:
    void Init(Window* WindowPointer);
    GLuint shaderProgram;






private:
    const char* vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";
    const char* fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
                                       "}\n\0";
};


class Render4V
{
private:
    bool Updated;
    void UpdateCords();
public:
    void SetShaderPrt(Shader* shader) {ShaderPRT = shader;}
    cordV4F CordClass;
    void Draw();
private:
    Shader* ShaderPRT;
    GLuint VAO , VBO;

};
