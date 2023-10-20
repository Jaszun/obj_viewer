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

#include "Renderer/Object.h"

class ObjFileManager: public FileManager
{
private:
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uv;

    std::vector<std::array<int, 9>> faces;

    std::vector<Vertex> vertices;

    std::vector<std::shared_ptr<Mesh>> meshes;

    std::string currentMesh = "";
public:
    const std::string commentToken = "#";

    std::shared_ptr<Object> object;

    ObjFileManager();

    void Init();
    void SaveData(std::string token, Converter* converter, std::vector<std::string> splittedLine);
    void InterpretData();
    void addVerticesTemp(std::vector<std::string> splittedLine);

    Converter* GetConverterByToken(std::string token);
};