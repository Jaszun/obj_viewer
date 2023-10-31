#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "FileReader/index.h"

class FileReader
{
private:
    std::vector<std::string> SplitLine(std::string line, char separator);

    FileManager* GetFileManager(std::string path);
public:
    FileManager* fileManager;

    bool fileRead = false;
    std::string fileExtension = "";

    FileReader();
    ~FileReader();

    void ReadFile(std::string path);
};