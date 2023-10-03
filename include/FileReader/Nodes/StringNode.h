#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class StringNode : public Node
{
public:
    std::string data;

    StringNode(std::vector<std::string> tokens) : Node(tokens){this->tokens = tokens;};

    void HandleData(std::vector<std::string> splittedLine);
};