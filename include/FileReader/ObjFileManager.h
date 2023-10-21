#pragma once

#include <iostream>
#include <array>

#include "FileManager.h"

#include "Renderer/Object.h"

class ObjFileManager: public FileManager
{
private:
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uv;

    std::string currentMesh = "";

    std::vector<Vertex> vertices;
    std::vector<std::shared_ptr<Mesh>> meshes;

    glm::vec2 GetGlmVec2(std::vector<std::string> splittedLine);
    glm::vec3 GetGlmVec3(std::vector<std::string> splittedLine);
    
    void LoadVerticesFromFace(std::vector<std::string> splittedLine);

    void SaveMesh();
public:
    const std::string commentToken = "#";

    std::shared_ptr<Object> object;

    ObjFileManager();

    void Init();
    void HandleData(std::string token, std::vector<std::string> splittedLine);
    void OnFileLoaded();
};