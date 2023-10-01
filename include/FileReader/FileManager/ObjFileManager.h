#pragma once

#include <iostream>

#include "FileManager.h"
#include "FileReader/Nodes/Node.h"

class ObjFileManager: public FileManager
{
public:
    ObjFileManager() : FileManager(){};

    void Init();
    Node* GetNodeBySymbol(std::string symbol);
};