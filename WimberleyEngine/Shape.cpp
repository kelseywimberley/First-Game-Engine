#include "pch.h"
#include "Shape.h"
#include <stdlib.h>

Shape::Shape(VertexData* vertices, size_t size)
{
    numVerts = size / sizeof(VertexData);
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    getGLError();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*)0);
    getGLError();
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*)(sizeof(float) * 3));
    getGLError();
}

void Shape::Draw()
{
    Use();
    glDrawArrays(GL_TRIANGLES, 0, numVerts);
    Unuse();
}

void Shape::Use()
{
    glBindVertexArray(vao);
}

void Shape::Unuse()
{
    glBindVertexArray(0);
}
