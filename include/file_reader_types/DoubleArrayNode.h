#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class DoubleArrayNode : public Node
{
public:
    DoubleArrayNode() : Node(){};

    void handleData(std::vector<std::string> splittedLine);
};