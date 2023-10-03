#pragma once

#include <iostream>
#include <vector>

class Node
{
public:
    std::vector<std::string> tokens;

    Node(std::vector<std::string> tokens);

    virtual void HandleData(std::vector<std::string> splittedLine) = 0;
};