#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class FileManager
{
protected:
    enum TokenSymbol;
    std::map<std::string, TokenSymbol> tokenMap;
public:
    std::string commentToken;
    std::string fileName;
    std::string dirPath;

    FileManager(std::string fileName, std::string dirPath);
    ~FileManager();

    virtual void Init() = 0;
    virtual void HandleData(std::string token, std::vector<std::string> splittedLine) = 0;
    virtual void OnFileLoaded() = 0;
};