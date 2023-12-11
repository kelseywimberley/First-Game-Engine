#pragma once
#include "VertexStruct.h"

class Shape
{
public:
    Shape(VertexData* vertices, size_t size);
    void Draw();
    void Use();
    void Unuse();

protected:
    GLuint vao;
    GLuint vertexBuffer;
    size_t numVerts;

    static void getGLError()
    {
        GLenum err = glGetError();
        if (GLEW_OK != err)
        {
            std::cout << "Terminating program. Reason:" << std::endl;
            std::cout << "Error in GLEW: " << glewGetErrorString(err) << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};
