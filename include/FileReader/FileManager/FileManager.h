#pragma once

#include <iostream>
#include <vector>

#include "FileReader/Nodes/index.h"

class FileManager
{
protected:
    std::vector<Node*> nodes;
public:
    FileManager(){};

    virtual void Init() = 0;
    virtual Node* GetNodeBySymbol(std::string symbol) = 0;
};