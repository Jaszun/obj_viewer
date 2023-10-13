#include "FileReader/Converters/StringConverter.h"

void StringConverter::Convert(std::vector<std::string> splittedLine)
{
    data = splittedLine.at(1);
}