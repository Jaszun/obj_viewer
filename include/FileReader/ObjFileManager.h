#pragma once

#include <iostream>
#include <array>

#include "common/Vertex.h"

#include "FileManager.h"

#include "Renderer/Object.h"

class ObjFileManager: public FileManager
{
private:
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uv;

    std::vector<Vertex> vertices;

    std::vector<std::shared_ptr<Mesh>> meshes;

    std::string currentMesh = "";

    glm::vec2 GetGlmVec2(std::vector<std::string> splittedLine);
    glm::vec3 GetGlmVec3(std::vector<std::string> splittedLine);
    
    void LoadVerticesFromFace(std::vector<std::string> splittedLine);
public:
    const std::string commentToken = "#";

    std::shared_ptr<Object> object;

    ObjFileManager();

    void Init();
    void HandleData(std::string token, std::vector<std::string> splittedLine);
    void OnFileLoaded();
};