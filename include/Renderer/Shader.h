#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

struct UniformInfo
{
    int location;
    int count;
};

class Shader
{
private:
    unsigned int shaderID;
    std::unordered_map<std::string, UniformInfo> uniforms;

    bool CheckUniform(const char *name);

public:
    Shader();
    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
    ~Shader();

    void Use();

    unsigned int CompileShader(const char *shaderPath, unsigned int shaderTarget);
    void ReadAllUniforms();
    void SetUniformVec3(glm::vec3 vec, const char *name);
};
