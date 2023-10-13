#include "FileReader/Converters/GlmVec2Converter.h"

void GlmVec2Converter::Convert(std::vector<std::string> splittedLine)
{
    glm::vec2 v
    (
        std::stof(splittedLine.at(1)),
        std::stof(splittedLine.at(2))
    );

    data = v;
}