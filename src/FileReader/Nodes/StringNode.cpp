#include "FileReader/Nodes/StringNode.h"

void StringNode::HandleData(std::vector<std::string> splittedLine)
{
    data = splittedLine.at(1);
}