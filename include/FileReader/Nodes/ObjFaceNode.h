#pragma once

#include <iostream>
#include <string>
#include <array>

#include "Node.h"

class ObjFaceNode : public Node
{
public:
    //indeksy dla vertexów
    std::array<int, 9> data;

    ObjFaceNode(std::vector<std::string> tokens) : Node(tokens){this->tokens = tokens;};

    void HandleData(std::vector<std::string> splittedLine);
};