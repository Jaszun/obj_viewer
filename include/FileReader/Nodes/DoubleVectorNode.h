#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class DoubleVectorNode : public Node
{
public:
    std::vector<double> data;

    DoubleVectorNode() : Node(){};
    DoubleVectorNode(std::vector<std::string> symbols) : Node(symbols){this->symbols = symbols;};

    void handleData(std::vector<std::string> splittedLine);
};