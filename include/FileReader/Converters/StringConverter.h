#pragma once

#include <iostream>
#include <string>

#include "Converter.h"

class StringConverter : public Converter
{
public:
    std::string data;

    StringConverter(std::vector<std::string> tokens) : Converter(tokens){this->tokens = tokens;};

    void Convert(std::vector<std::string> splittedLine);
};