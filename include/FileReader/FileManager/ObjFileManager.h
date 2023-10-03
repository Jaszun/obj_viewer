#pragma once

#include <iostream>

#include "FileManager.h"
#include "FileReader/Nodes/Node.h"

class ObjFileManager: public FileManager
{
private:
    std::vector<std::vector<double>> vertices;
    std::string meshName;
    std::string mtlName;
public:
    ObjFileManager() : FileManager(){};

    void Init();
    void SaveNodeData(std::string token, Node* node);
    void InterpretData();

    Node* GetNodeByToken(std::string token);
};