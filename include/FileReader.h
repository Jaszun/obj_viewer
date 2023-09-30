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

public:
    FileReader();
    ~FileReader();

    void ReadFile(std::string path);
};