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

Node* ObjFileManager::GetNodeBySymbol(std::string symbol)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        std::vector<std::string> symbols = nodes.at(i)->symbols;

        if (std::find(symbols.begin(), symbols.end(), symbol) != symbols.end())
            return nodes.at(i);
    }
    
    return nullptr;
}