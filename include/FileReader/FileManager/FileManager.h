#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "FileReader/Converters/Converter.h"

class FileManager
{
protected:
    std::vector<Converter*> converters;
public:
    FileManager(){};

    Converter* GetConverterByToken(std::string token);

    virtual void Init() = 0;
    virtual void SaveData(std::string token, Converter* converter) = 0;
    virtual void InterpretData() = 0;
};