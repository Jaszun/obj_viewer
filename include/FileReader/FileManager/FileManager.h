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

    Node* GetNodeByToken(std::string token);

    virtual void Init() = 0;
    virtual void SaveNodeData(std::string token, Node* node) = 0;
    virtual void InterpretData() = 0;
};