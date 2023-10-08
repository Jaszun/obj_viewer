#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>

#include "Node.h"

class GlmVec3Node : public Node
{
public:
    glm::vec3 data;

    GlmVec3Node(std::vector<std::string> tokens) : Node(tokens){this->tokens = tokens;};

    void HandleData(std::vector<std::string> splittedLine);
};