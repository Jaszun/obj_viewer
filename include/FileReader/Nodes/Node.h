#pragma once

#include <iostream>
#include <vector>

class Node
{
public:
    std::vector<std::string> symbols;

    Node();
    Node(std::vector<std::string> symbols);

    virtual void handleData(std::vector<std::string> splittedLine) = 0;
};