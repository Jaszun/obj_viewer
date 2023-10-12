#pragma once

#include <iostream>
#include <array>

#include "FileManager.h"
#include "FileReader/Nodes/Node.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;
};

class ObjFileManager: public FileManager
{
private:
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> normals;

    std::vector<Vertex> vertices;

    std::vector<std::array<int, 9>> faces;

    std::string meshName;
    std::string mtlName;
public:
    ObjFileManager() : FileManager(){};

    void Init();
    void SaveNodeData(std::string token, Node* node);
    void InterpretData();

    Node* GetNodeByToken(std::string token);
};