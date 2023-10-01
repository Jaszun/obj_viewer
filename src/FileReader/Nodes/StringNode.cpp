#include "FileReader/Nodes/StringNode.h"

void StringNode::handleData(std::vector<std::string> splittedLine)
{
    std::cout << "string\n";

    std::cout << splittedLine.at(1) << "\n";
}