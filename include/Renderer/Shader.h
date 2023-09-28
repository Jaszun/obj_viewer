#pragma once

#include <iostream>
#include <fstream>
#include "glad/glad.h"

class Shader
{
private:
    unsigned int shaderID = -1;

public:
    Shader();
    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
    ~Shader();

    void Use();

    unsigned int CompileShader(const char *shaderPath, unsigned int shaderTarget);
};
