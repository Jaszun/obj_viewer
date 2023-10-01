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

    Node* GetNodeBySymbol(std::string symbol);

    virtual void Init() = 0;
    virtual void SaveNodeData(std::string symbol, Node* node) = 0;
    virtual void InterpretData() = 0;
};