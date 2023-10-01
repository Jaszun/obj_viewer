#pragma once

#include <iostream>
#include <algorithm>

#include "FileManager.h"
#include "FileReader/Nodes/index.h"

class ObjFileManager: public FileManager
{
public:
    ObjFileManager() : FileManager(){};

    void Init();
    Node* GetNodeBySymbol(std::string symbol);
};