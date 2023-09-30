#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class StringNode : public Node
{
public:
    StringNode() : Node(){};

    void handleData(std::vector<std::string> splittedLine);
};