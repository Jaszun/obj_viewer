#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>

#include "Converter.h"

class GlmVec2Converter : public Converter
{
public:
    glm::vec2 data;

    GlmVec2Converter(std::vector<std::string> tokens);

    void Convert(std::vector<std::string> splittedLine);
};