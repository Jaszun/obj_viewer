#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>

#include "Converter.h"

class GlmVec3Converter : public Converter
{
public:
    glm::vec3 data;

    GlmVec3Converter(std::vector<std::string> tokens);

    void Convert(std::vector<std::string> splittedLine);
};