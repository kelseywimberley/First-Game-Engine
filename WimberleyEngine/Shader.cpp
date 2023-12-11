#include "pch.h"
#include "Shader.h"

Shader::Shader(VertexData* vertices, size_t size)
{
    static const char* vertexShaderCode =
        "#version 400\n"
        "uniform mat4 MVP;\n"
        "layout (location=0) in vec3 vertex_position;\n"
        "layout (location=1) in vec3 vertex_color;\n"
        "out vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = MVP * vec4(vertex_position, 1.0);\n"
        "    color = vertex_color;\n"
        "}\n";

    static const char* fragmentShaderCode =
        "#version 400\n"
        "in vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = vec4(color, 1.0);\n"
        "}\n";

    GLuint vertexShader, fragmentShader, shaderProgram;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShader);
    getShaderCompilationError(vertexShader);
    getGLError();

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShader);
    getShaderCompilationError(fragmentShader);
    getGLError();

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    getGLError();

    GLint mvpLocation, vertexPositionLocation, vertexColorLocation;
    mvpLocation = glGetUniformLocation(shaderProgram, "MVP");
    vertexPositionLocation = glGetAttribLocation(shaderProgram, "vertex_position");
    vertexColorLocation = glGetAttribLocation(shaderProgram, "vertex_color");
    getGLError();

    ID = shaderProgram;
    MVPLoc = mvpLocation;
    s = size / sizeof(VertexData);
}

void Shader::Use(glm::mat4 mvp)
{
    glUseProgram(ID);
    getGLError();
    glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, &mvp[0][0]);
    getGLError();
}

void Shader::Unuse()
{
    glUseProgram(0);
    getGLError();
}
