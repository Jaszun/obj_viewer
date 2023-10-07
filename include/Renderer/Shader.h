#pragma once

#include <iostream>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
TODO:
[] read and store uniform names, types
[] whenever an uniform is about to be changed check whether it exists and if the type matches
*/

class Shader
{
private:
    unsigned int shaderID;

public:
    Shader();
    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
    ~Shader();

    void Use();

    unsigned int CompileShader(const char *shaderPath, unsigned int shaderTarget);
    void SetUniformVec3(glm::vec3 vec, const char *name);
};
