#include "FileReader/FileManager/ObjFileManager.h"

void ObjFileManager::Init()
{
    nodes = 
    {
        new DoubleVectorNode({"v", "vn", "vt"}),
        new StringNode({"mtllib", "o", "usemtl"}),
        // new IntNode("s"),
        // new VertexNode("f"),
    };
}