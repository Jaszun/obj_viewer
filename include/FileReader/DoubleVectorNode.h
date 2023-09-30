#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class DoubleVectorNode : public Node
{
public:
    DoubleVectorNode() : Node(){};

    void handleData(std::vector<std::string> splittedLine);
};