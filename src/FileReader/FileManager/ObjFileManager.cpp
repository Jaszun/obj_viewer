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
        new StringConverter({"mtllib", "o", "usemtl"})
        // new IntConverter("s"),
        // new IntVectorConverter("l"),
    };
}

void ObjFileManager::SaveData(std::string token, Converter* converter)
{
    if (token == "v")
        positions.push_back(((GlmVec3Converter*) converter)->data);
    else if (token == "vn")
        normals.push_back(((GlmVec3Converter*) converter)->data);
    else if (token == "vt")
        uv.push_back(((GlmVec2Converter*) converter)->data);
    else if (token == "f")
        faces.push_back(((ObjFaceConverter*) converter)->data);
    // temp
    //
    // else if (token == "vp")
    //     uv.push_back(((DoubleVectorConverter*) converter)->data);
    // else if (token == "mtllib")
    //     mtllib = ((StringConverter*) converter)->data;
    else if (token == "o")
        meshName = ((StringConverter*) converter)->data;
    else if (token == "usemtl")
        mtlName = ((StringConverter*) converter)->data;
    // else if (token == "s")
    //     smoothShading = ((IntConverter*) converter)->data;
    // else if (token == "l")
    //     lines.push_back(((IntVectorConverter*) converter)->data);
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
                    normals.at(face[2 + vertexIndex]),
                    uv.at(face[1 + vertexIndex])
                });
        }
    }

    // temp
    std::cout << "Mesh name: " << meshName << "\n";
    std::cout << "Material: " << mtlName << "\n";
}