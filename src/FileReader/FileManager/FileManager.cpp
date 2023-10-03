#include "FileReader/FileManager/FileManager.h"

Node* FileManager::GetNodeByToken(std::string token)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        std::vector<std::string> tokens = nodes.at(i)->tokens;

        if (std::find(tokens.begin(), tokens.end(), token) != tokens.end())
            return nodes.at(i);
    }
    
    return nullptr;
}