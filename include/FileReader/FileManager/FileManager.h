#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "FileReader/Nodes/index.h"

class FileManager
{
protected:
    std::vector<Node*> nodes;
public:
    FileManager(){};

    virtual void Init() = 0;

    Node* GetNodeBySymbol(std::string symbol);
};