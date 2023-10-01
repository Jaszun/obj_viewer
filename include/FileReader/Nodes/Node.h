#pragma once

#include <iostream>
#include <vector>

class Node
{
public:
    std::vector<std::string> symbols;

    Node(std::vector<std::string> symbols);

    virtual void HandleData(std::vector<std::string> splittedLine) = 0;
};