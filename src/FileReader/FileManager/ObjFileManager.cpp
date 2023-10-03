#include "FileReader/FileManager/ObjFileManager.h"

void ObjFileManager::Init()
{
    //TODO: pytanie do Antona: co w zasadzie jest nam potrzebne?
    nodes = 
    {
        new DoubleVectorNode({"v", "vn", "vt", "vp"}),
        new StringNode({"mtllib", "o", "usemtl"}),
        // new IntNode("s"),
        // new IntVectorNode("l"),
        // new VertexNode("f"),
    };
}

void ObjFileManager::SaveNodeData(std::string token, Node* node)
{
    if (token == "v")
        vertices.push_back(((DoubleVectorNode*) node)->data);
    // else if (token == "vn")
    //     textureCoords.push_back(((DoubleVectorNode*) node)->data);
    // else if (token == "vt")
    //     vertexNormals.push_back(((DoubleVectorNode*) node)->data);
    // else if (token == "vp")
    //     uv.push_back(((DoubleVectorNode*) node)->data);
    // else if (token == "mtllib")
    //     mtllib = ((StringNode*) node)->data;
    else if (token == "o")
        meshName = ((StringNode*) node)->data;
    else if (token == "usemtl")
        mtlName = ((StringNode*) node)->data;
    // else if (token == "s")
    //     smoothShading = ((IntNode*) node)->data;
    // else if (token == "l")
    //     lines.push_back(((IntVectorNode*) node)->data);
    // else if (token == "f")
    //     faces.push_back(((VertexNode*) node)->data);
}

void ObjFileManager::InterpretData()
{
    // temp

    std::cout << "Vertices:\n";

    for (int i = 0; i < vertices.size(); i++)
    {
        std::vector<double> vertex = vertices.at(i);

        for (int j = 0; j < vertex.size(); j++)
        {
            std::cout << vertex.at(j) << " ";
        }

        std::cout << "\n";
    }

    std::cout << "Mesh name: " << meshName << "\n";
    std::cout << "Material: " << mtlName << "\n";
}