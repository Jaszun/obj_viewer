#include "Renderer/Shader.h"

Shader::Shader()
{
}

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    unsigned int vertexShader = CompileShader(vertexShaderPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = CompileShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertexShader);
    glAttachShader(shaderID, fragmentShader);
    glLinkProgram(shaderID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    // robi seg fault to może lepiej nie, trzeba będzie potem ogarnąć żeby renderer czyścił programy czy coś
    // glDeleteProgram(shaderID);
}

void Shader::Use()
{
    glUseProgram(shaderID);
}

unsigned int Shader::CompileShader(const char *shaderPath, unsigned int shaderTarget)
{
    std::string shaderSource{};
    std::fstream shaderFile(shaderPath);

    if (shaderFile.is_open())
    {
        while (shaderFile)
        {
            std::string line{};
            std::getline(shaderFile, line);

            shaderSource += line + '\n';
        }
        std::cout << shaderSource << '\n';
    }
    else
    {
        std::cout << "ERROR file couldn't be opened\n";
    }

    const char *ptr = shaderSource.c_str();

    unsigned int shader = glCreateShader(shaderTarget);
    glShaderSource(shader, 1, &ptr, NULL);
    glCompileShader(shader);

    return shader;
}
