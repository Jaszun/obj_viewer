#include "FileReader/FileManager/ObjFileManager.h"

void ObjFileManager::Init()
{
    nodes = 
    {
        new DoubleVectorNode({"v", "vn", "vt", "vp"}),
        new StringNode({"mtllib", "o", "usemtl"}),
        // new IntNode("s"),
        // new IntVectorNode("l"),
        // new VertexNode("f"),
    };
}

void ObjFileManager::SaveNodeData(std::string symbol, Node* node)
{
    if (symbol == "v")
        vertices.push_back(((DoubleVectorNode*) node)->data);
    // else if (symbol == "vn")
    //     textureCoords.push_back(((DoubleVectorNode*) node)->data);
    // else if (symbol == "vt")
    //     vertexNormals.push_back(((DoubleVectorNode*) node)->data);
    // else if (symbol == "vp")
    //     uv.push_back(((DoubleVectorNode*) node)->data);
    // else if (symbol == "mtllib")
    //     mtllib = ((StringNode*) node)->data;
    else if (symbol == "o")
        meshName = ((StringNode*) node)->data;
    else if (symbol == "usemtl")
        mtlName = ((StringNode*) node)->data;
    // else if (symbol == "s")
    //     smoothShading = ((IntNode*) node)->data;
    // else if (symbol == "l")
    //     lines.push_back(((IntVectorNode*) node)->data);
    // else if (symbol == "f")
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