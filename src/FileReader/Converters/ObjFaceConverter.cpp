#include "FileReader/Converters/ObjFaceConverter.h"

std::vector<int> splitLine(std::string line, char separator)
{
    std::vector<int> splittedLine;

    std::string temp = "";

    int index = 0;
   
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != separator)
            temp += line[i];
        
        else
        {
            splittedLine.push_back(std::stoi(temp));
            temp = "";
        }
    }

    splittedLine.push_back(std::stoi(temp));

    return splittedLine;
}

void ObjFaceConverter::Convert(std::vector<std::string> splittedLine)
{
    int index = 0;

    for (int i = 1; i <= 3; i++)
    {
        std::vector<int> vertexInfo = splitLine(splittedLine.at(i), '/');

        for (int j = 0; j < 3; j++)
        {
            //-1 bo to indexy
            data[index++] = vertexInfo.at(j) - 1;
        }
    }
}