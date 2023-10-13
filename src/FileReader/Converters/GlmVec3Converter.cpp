#include "FileReader/Converters/GlmVec3Converter.h"

void GlmVec3Converter::Convert(std::vector<std::string> splittedLine)
{
    glm::vec3 v
    (
        std::stof(splittedLine.at(1)),
        std::stof(splittedLine.at(2)),
        std::stof(splittedLine.at(3))
    );

    data = v;
}