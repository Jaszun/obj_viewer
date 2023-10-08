#include "FileReader/Nodes/GlmVec3Node.h"

void GlmVec3Node::HandleData(std::vector<std::string> splittedLine)
{
    glm::vec3 v
    (
        std::stof(splittedLine.at(1)),
        std::stof(splittedLine.at(2)),
        std::stof(splittedLine.at(3))
    );

    data = v;
}