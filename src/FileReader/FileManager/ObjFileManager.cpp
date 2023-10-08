#include "FileReader/FileManager/ObjFileManager.h"

void ObjFileManager::Init()
{
    nodes = 
    {
        new GlmVec3Node({"v", "vn"}),
        // new GlmVec2Node({"vt"}),
        new StringNode({"mtllib", "o", "usemtl"}),
        // new IntNode("s"),
        // new IntVectorNode("l"),
        // new VertexNode("f"),
    };
}

void ObjFileManager::SaveNodeData(std::string token, Node* node)
{
    if (token == "v")
        positions.push_back(((GlmVec3Node*) node)->data);
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

    std::cout << "Positions:\n";

    for (int i = 0; i < positions.size(); i++)
    {
        glm::vec3 position = positions.at(i);

        std::cout << position.x << " ";
        std::cout << position.y << " ";
        std::cout << position.z << "\n";
    }

    std::cout << "Mesh name: " << meshName << "\n";
    std::cout << "Material: " << mtlName << "\n";
}