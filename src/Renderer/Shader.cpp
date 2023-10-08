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

    ReadAllUniforms();
}

Shader::~Shader()
{
    // robi seg fault to może lepiej nie, trzeba będzie potem ogarnąć żeby renderer czyścił programy czy coś
    std::cout << "Shader destructor\n";
    glDeleteProgram(shaderID);
}

bool Shader::CheckUniform(const char *name)
{
    if (uniforms.find(name) != uniforms.end())
        return true;
    return false;
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

/**
 * courtesy of https://github.com/fendevel/Guide-to-Modern-OpenGL-Functions#ideal-way-of-retrieving-all-uniform-names
 */
void Shader::ReadAllUniforms()
{
    GLint uniform_count = 0;
    glGetProgramiv(shaderID, GL_ACTIVE_UNIFORMS, &uniform_count);

    if (uniform_count != 0)
    {
        GLint max_name_len = 0;
        GLsizei length = 0;
        GLsizei count = 0;
        GLenum type = GL_NONE;
        glGetProgramiv(shaderID, GL_ACTIVE_UNIFORM_MAX_LENGTH, &max_name_len);

        auto uniform_name = std::make_unique<char[]>(max_name_len);

        for (GLint i = 0; i < uniform_count; ++i)
        {
            glGetActiveUniform(shaderID, i, max_name_len, &length, &count, &type, uniform_name.get());

            UniformInfo uniform_info = {
                glGetUniformLocation(shaderID, uniform_name.get()),
                count};

            uniforms.emplace(std::make_pair(std::string(uniform_name.get(), length), uniform_info));
        }
    }
}

void Shader::SetUniformVec3(glm::vec3 vec, const char *name)
{
    if (CheckUniform(name))
    {
        glUniform3fv(uniforms[name].location, uniforms[name].count, glm::value_ptr(vec));
        // std::cout << name << " " << uniforms[name].count << " " << uniforms[name].location << " " << vec.z << "\n";
    }
}
