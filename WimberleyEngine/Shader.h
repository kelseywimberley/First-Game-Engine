#pragma once
#include "VertexStruct.h"
#include "glm/mat4x4.hpp"

class Shader
{
public:
    GLuint ID;
    GLint MVPLoc;
    size_t s;

    Shader(VertexData* vertices, size_t size);

    void Use(glm::mat4 mvp);
    void Unuse();

private:
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

    static void getShaderCompilationError(GLuint shader)
    {
        int  success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "COMPILATION_FAILED\n" << infoLog << std::endl;
        }
    }
};
