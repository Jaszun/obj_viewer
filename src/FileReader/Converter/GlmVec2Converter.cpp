#include "FileReader/Converter/GlmVec2Converter.h"

GlmVec2Converter::GlmVec2Converter(std::vector<std::string> tokens) : Converter(tokens)
{
}

void GlmVec2Converter::Convert(std::vector<std::string> splittedLine)
{
    glm::vec2 v
    (
        std::stof(splittedLine.at(1)),
        std::stof(splittedLine.at(2))
    );

    data = v;
}