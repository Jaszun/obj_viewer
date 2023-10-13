#pragma once

#include <iostream>
#include <array>

#include "common/Vertex.h"

#include "FileManager.h"

#include "FileReader/Converter/Converter.h"
#include "FileReader/Converter/GlmVec2Converter.h"
#include "FileReader/Converter/GlmVec3Converter.h"
#include "FileReader/Converter/StringConverter.h"
#include "FileReader/Converter/ObjFaceConverter.h"

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