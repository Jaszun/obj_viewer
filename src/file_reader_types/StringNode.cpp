#include "file_reader_types/StringNode.h"

void StringNode::handleData(std::vector<std::string> splittedLine)
{
    std::cout << "string\n";

    for (int i = 1; i < splittedLine.size(); i++)
    {
        std::cout << splittedLine.at(i) << "\n";
    }
    // std::cout << splittedLine.at(1) << "\n";
}