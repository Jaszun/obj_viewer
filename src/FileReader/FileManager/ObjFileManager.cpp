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
    // chyba może być vector, prawda?
    //
    // prawda?
    //
    // glBufferData(
    // GL_ARRAY_BUFFER,
    // vertices.size() * sizeof(Vertex),
    // &vertices.front(),
    // GL_STATIC_DRAW
    // );

    // TODO: FaceNode
    //
    // for (int i = 0; i < faces.size(); i++)
    // {
    //     
    //     
    //     if (vertex not in vertices)
    //         
    //
    //     vertices.push_back({ positions.at(i), normals.at(i), uv.at(i) });

    //     std::cout << i << "\n";
    // }

    std::cout << "Mesh name: " << meshName << "\n";
    std::cout << "Material: " << mtlName << "\n";
}