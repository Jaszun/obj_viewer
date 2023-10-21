#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class FileManager
{
public:
    std::string commentToken;
    std::string fileName;

    FileManager(std::string fileName);
    ~FileManager();

    virtual void Init() = 0;
    virtual void HandleData(std::string token, std::vector<std::string> splittedLine) = 0;
    virtual void OnFileLoaded() = 0;
};