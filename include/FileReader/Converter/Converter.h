#pragma once

#include <iostream>
#include <vector>

class Converter
{
public:
    std::vector<std::string> tokens;

    Converter(std::vector<std::string> tokens);
    ~Converter();

    // A method which converts the given line of file to a specific data format and stores the result in `data` field. Specific to each derived class.
    virtual void Convert(std::vector<std::string> splittedLine) = 0;
};