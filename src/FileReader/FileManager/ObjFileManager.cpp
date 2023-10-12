#include "FileReader/FileManager/ObjFileManager.h"

void ObjFileManager::Init()
{
    nodes = 
    {
        new GlmVec3Node({"v", "vn"}),
        new GlmVec2Node({"vt"}),
        new StringNode({"mtllib", "o", "usemtl"}),
        // new IntNode("s"),
        // new IntVectorNode("l"),
        new ObjFaceNode({"f"}),
    };
}

void ObjFileManager::SaveNodeData(std::string token, Node* node)
{
    if (token == "v")
        positions.push_back(((GlmVec3Node*) node)->data);
    else if (token == "vn")
        normals.push_back(((GlmVec3Node*) node)->data);
    else if (token == "vt")
        uv.push_back(((GlmVec2Node*) node)->data);
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
    else if (token == "f")
        faces.push_back(((ObjFaceNode*) node)->data);
}

void ObjFileManager::InterpretData()
{
    for (int i = 0; i < faces.size(); i++)
    {
        std::array<int, 9> face = faces.at(i);

        for (int j = 0; j < 3; j++)
        {
            int vertexIndex = j * 3;

            vertices.push_back(
                {
                    positions.at(face[0 + vertexIndex]),
                    uv.at(face[1 + vertexIndex]),
                    normals.at(face[2 + vertexIndex])
                });
        }
    }

    std::cout << "Mesh name: " << meshName << "\n";
    std::cout << "Material: " << mtlName << "\n";
}