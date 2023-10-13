#pragma once

#include <iostream>
#include <vector>

class Converter
{
public:
    std::vector<std::string> tokens;

    Converter(std::vector<std::string> tokens);

    virtual void Convert(std::vector<std::string> splittedLine) = 0;
};