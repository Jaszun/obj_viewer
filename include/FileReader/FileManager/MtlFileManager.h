#pragma once

#include <iostream>
#include <array>

#include "FileManager.h"

#include "FileReader/Converter/Converter.h"
#include "FileReader/Converter/GlmVec3Converter.h"
#include "FileReader/Converter/StringConverter.h"

class MtlFileManager: public FileManager
{
public:
    const std::string commentToken = "#";

    MtlFileManager();

    void Init();
    void SaveData(std::string token, Converter* converter, std::vector<std::string> splittedLine);
    void InterpretData();

    Converter* GetConverterByToken(std::string token);
};