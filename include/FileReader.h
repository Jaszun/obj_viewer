#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "file_reader_types/Node.h"
#include "file_reader_types/DoubleArrayNode.h"
#include "file_reader_types/StringNode.h"

class FileReader
{
private:
    std::vector<std::string> SplitLine(std::string line, char separator);

public:
    FileReader();
    ~FileReader();

    void ReadFile(std::string path);
};