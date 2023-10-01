#include "FileReader/Nodes/DoubleVectorNode.h"

void DoubleVectorNode::HandleData(std::vector<std::string> splittedLine)
{
    std::vector<double> doubleVector;

    for (int i = 1; i < splittedLine.size(); i++)
    {
        doubleVector.push_back(std::stod(splittedLine.at(i)));
    }

    data = doubleVector;
}