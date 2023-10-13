#include "FileReader/Converter/StringConverter.h"

StringConverter::StringConverter(std::vector<std::string> tokens) : Converter(tokens)
{
}

void StringConverter::Convert(std::vector<std::string> splittedLine)
{
    data = splittedLine.at(1);
}