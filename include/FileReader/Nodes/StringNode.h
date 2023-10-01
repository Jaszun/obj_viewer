#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class StringNode : public Node
{
public:
    std::string data;

    StringNode() : Node(){};
    StringNode(std::vector<std::string> symbols) : Node(symbols){this->symbols = symbols;};

    void handleData(std::vector<std::string> splittedLine);
};