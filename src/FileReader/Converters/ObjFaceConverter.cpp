#include "FileReader/Converters/ObjFaceConverter.h"

ObjFaceConverter::ObjFaceConverter(std::vector<std::string> tokens) : Converter(tokens)
{
}

std::vector<int> ObjFaceConverter::GetIndexesForVertex(std::string line)
{
    std::vector<int> indexes;

    std::string temp = "";

    char separator = '/';

    int index = 0;
   
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != separator)
            temp += line[i];
        
        else
        {
            indexes.push_back(std::stoi(temp));
            temp = "";
        }
    }

    indexes.push_back(std::stoi(temp));

    return indexes;
}

void ObjFaceConverter::Convert(std::vector<std::string> splittedLine)
{
    int index = 0;

    for (int i = 1; i <= 3; i++)
    {
        std::vector<int> indexesForVertex = GetIndexesForVertex(splittedLine.at(i));

        for (int j = 0; j < 3; j++)
        {
            // -1 because these are indexes
            data[index++] = indexesForVertex.at(j) - 1;
        }
    }
}