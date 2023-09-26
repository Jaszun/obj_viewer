#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileReader
{
public:
    FileReader();
    ~FileReader();

    void ReadFile(std::string path);
};