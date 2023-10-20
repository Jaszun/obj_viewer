#pragma once

#include <iostream>
#include <array>

#include "FileManager.h"

class MtlFileManager: public FileManager
{
public:
    const std::string commentToken = "#";

    MtlFileManager();

    void Init();
    void HandleData(std::string token, std::vector<std::string> splittedLine);
    void OnFileLoaded();
};