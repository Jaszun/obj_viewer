#pragma once

#include <iostream>
#include <string>
#include <array>

#include "Converter.h"

class ObjFaceConverter : public Converter
{
public:
    // data indexes for 3 vertices
    std::array<int, 9> data;

    ObjFaceConverter(std::vector<std::string> tokens) : Converter(tokens){this->tokens = tokens;};

    void Convert(std::vector<std::string> splittedLine);
};