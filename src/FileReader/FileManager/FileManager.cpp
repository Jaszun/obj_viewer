#include "FileReader/FileManager/FileManager.h"

Node* FileManager::GetNodeBySymbol(std::string symbol)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        std::vector<std::string> symbols = nodes.at(i)->symbols;

        if (std::find(symbols.begin(), symbols.end(), symbol) != symbols.end())
            return nodes.at(i);
    }
    
    return nullptr;
}