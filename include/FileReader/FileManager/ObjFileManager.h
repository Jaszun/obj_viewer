#pragma once

#include <iostream>
#include <array>

#include "FileManager.h"
#include "FileReader/Converters/Converter.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

class ObjFileManager: public FileManager
{
private:
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uv;

    std::vector<Vertex> vertices;

    std::vector<std::array<int, 9>> faces;

    std::string meshName;
    std::string mtlName;
public:
    ObjFileManager() : FileManager(){};

    void Init();
    void SaveData(std::string token, Converter* converter);
    void InterpretData();

    Converter* GetConverterByToken(std::string token);
};