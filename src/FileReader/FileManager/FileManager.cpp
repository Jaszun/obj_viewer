#include "FileReader/FileManager/FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

Converter* FileManager::GetConverterByToken(std::string token)
{
    for (int i = 0; i < converters.size(); i++)
    {
        std::vector<std::string> tokens = converters.at(i)->tokens;

        if (std::find(tokens.begin(), tokens.end(), token) != tokens.end())
            return converters.at(i);
    }
    
    return nullptr;
}