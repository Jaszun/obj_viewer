#include "FileReader/FileManager/ObjFileManager.h"

ObjFileManager::ObjFileManager() : FileManager()
{
}

void ObjFileManager::Init()
{
    converters = 
    {
        new GlmVec3Converter({"v", "vn"}),
        new GlmVec2Converter({"vt"}),
        new ObjFaceConverter({"f"}),
        // temp - depends on what we need
        new StringConverter({"usemtl"})
        // new IntConverter("s"),
        // new IntVectorConverter("l"),
    };
}

void ObjFileManager::SaveData(std::string token, Converter* converter, std::vector<std::string> splittedLine)
{
    if (token == "v")
        positions.push_back(((GlmVec3Converter*) converter)->data);
    else if (token == "vn")
        normals.push_back(((GlmVec3Converter*) converter)->data);
    else if (token == "vt")
        uv.push_back(((GlmVec2Converter*) converter)->data);
    else if (token == "f")
    {
        addVerticesTemp(splittedLine);
        // faces.push_back(((ObjFaceConverter*) converter)->data);
    }
    // temp
    //
    // else if (token == "vp")
    //     uv.push_back(((DoubleVectorConverter*) converter)->data);
    // else if (token == "mtllib")
    //     mtllib = ((StringConverter*) converter)->data;
    // else if (token == "o")
    //     meshName = ((StringConverter*) converter)->data;
    else if (token == "usemtl")
    {
        if (currentMesh == "")
        {
            currentMesh = splittedLine.at(1);
        }

        else
        {
            meshes.emplace_back(std::make_shared<Mesh>(std::move(vertices)));
            vertices.clear();

            std::cout << "Mesh " + currentMesh + " loaded!\n";
        }
    }
    // else if (token == "s")
    //     smoothShading = ((IntConverter*) converter)->data;
    // else if (token == "l")
    //     lines.push_back(((IntVectorConverter*) converter)->data);
}

void ObjFileManager::InterpretData()
{
    meshes.emplace_back(std::make_shared<Mesh>(std::move(vertices)));
    vertices.clear();

    std::cout << "Mesh " + currentMesh + " loaded!\n";

    object = std::make_shared<Object>(std::move(meshes));
}

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

void ObjFileManager::addVerticesTemp(std::vector<std::string> splittedLine)
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