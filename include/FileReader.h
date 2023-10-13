#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "FileReader/Converters/Converter.h"
#include "FileReader/FileManager/index.h"

class FileReader
{
private:
    std::vector<std::string> SplitLine(std::string line, char separator);

    FileManager* GetFileManager(std::string path);
public:
    FileReader();
    ~FileReader();

    void ReadFile(std::string path);
};