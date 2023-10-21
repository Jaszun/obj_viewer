#include "FileReader/ObjFileManager.h"

ObjFileManager::ObjFileManager() : FileManager()
{
}

void ObjFileManager::Init()
{
}

void ObjFileManager::HandleData(std::string token, std::vector<std::string> splittedLine)
{
    if (token == "v")
        positions.push_back(GetGlmVec3(splittedLine));
    else if (token == "vn")
        normals.push_back(GetGlmVec3(splittedLine));
    else if (token == "vt")
        uv.push_back(GetGlmVec2(splittedLine));
    else if (token == "f")
        LoadVerticesFromFace(splittedLine);
    else if (token == "usemtl")
    {
        if (currentMesh != "")
            SaveMesh();
        
        currentMesh = splittedLine.at(1);
    }
    // else if (token == "vp")
    //     uv.push_back(((DoubleVectorConverter*) converter)->data);
    // else if (token == "mtllib")
    //     mtllib = ((StringConverter*) converter)->data;
    // else if (token == "o")
    //     meshName = ((StringConverter*) converter)->data;
    // else if (token == "s")
    //     smoothShading = ((IntConverter*) converter)->data;
    // else if (token == "l")
    //     lines.push_back(((IntVectorConverter*) converter)->data);
}

void ObjFileManager::OnFileLoaded()
{
    SaveMesh();

    object = std::make_shared<Object>(std::move(meshes));
}

void ObjFileManager::SaveMesh()
{
    meshes.emplace_back(std::make_shared<Mesh>(std::move(vertices), std::move(currentMesh)));
    vertices.clear();

    std::cout << "Mesh " + currentMesh + " loaded!\n";
}

// data mamaging functions

std::vector<int> GetIndexesForVertex(std::string line)
{
    std::vector<int> indexes;

    std::string temp = "";

    char separator = '/';
   
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != separator)
            temp += line[i];
        
        else
        {
            indexes.push_back(std::stoi(temp));
            temp = "";
        }
    }

    indexes.push_back(std::stoi(temp));

    return indexes;
}

glm::vec2 ObjFileManager::GetGlmVec2(std::vector<std::string> splittedLine)
{
    return glm::vec2
        (
            std::stof(splittedLine.at(1)),
            std::stof(splittedLine.at(2))
        );
}

glm::vec3 ObjFileManager::GetGlmVec3(std::vector<std::string> splittedLine)
{
    return glm::vec3
        (
            std::stof(splittedLine.at(1)),
            std::stof(splittedLine.at(2)),
            std::stof(splittedLine.at(3))
        );
}

void ObjFileManager::LoadVerticesFromFace(std::vector<std::string> splittedLine)
{
    int index = 0;

    for (int i = 1; i <= 3; i++)
    {
        std::vector<int> indexesForVertex = GetIndexesForVertex(splittedLine.at(i));

        vertices.push_back(
        {
            // -1 because these are indexes
            positions.at(indexesForVertex.at(0) - 1),
            normals.at(indexesForVertex.at(2) - 1),
            uv.at(indexesForVertex.at(1) - 1)
        });
    }
}