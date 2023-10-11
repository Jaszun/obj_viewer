#include "FileReader/Nodes/GlmVec2Node.h"

void GlmVec2Node::HandleData(std::vector<std::string> splittedLine)
{
    glm::vec2 v
    (
        std::stof(splittedLine.at(1)),
        std::stof(splittedLine.at(2))
    );

    data = v;
}