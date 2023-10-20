#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "FileReader/Converter/Converter.h"

class FileManager
{
protected:
    std::vector<Converter*> converters;
public:
    std::string commentToken;

    FileManager();
    ~FileManager();

    Converter* GetConverterByToken(std::string token);

    virtual void Init() = 0;
    virtual void SaveData(std::string token, Converter* converter, std::vector<std::string> splittedLine) = 0;
    virtual void InterpretData() = 0;
};