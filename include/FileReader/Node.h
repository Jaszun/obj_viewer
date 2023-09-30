#pragma once

#include <iostream>
#include <vector>

class Node
{
public:
    std::string* symbols;

    Node(){};

    virtual void handleData(std::vector<std::string> splittedLine) = 0;
};