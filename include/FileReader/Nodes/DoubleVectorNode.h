#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class DoubleVectorNode : public Node
{
public:
    std::vector<double> data;

    DoubleVectorNode(std::vector<std::string> tokens) : Node(tokens){this->tokens = tokens;};

    void HandleData(std::vector<std::string> splittedLine);
};