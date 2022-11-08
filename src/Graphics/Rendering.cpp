#include "Graphics.hpp"



void win::RunDeffult() {}


cordV4F::cordV4F() {
    Updated = false;

}



void Render4V::Draw() {
    GLfloat vertex[] = {
            -1,0,0,
            -1,1,0,
             0,0,0
    };

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glUseProgram(ShaderPRT->shaderProgram);
    // Bind the VAO so OpenGL knows to use it
    glBindVertexArray(VAO);
    // Draw the triangle using the GL_TRIANGLES primitive
    glDrawArrays(GL_TRIANGLES, 0, 3);

}