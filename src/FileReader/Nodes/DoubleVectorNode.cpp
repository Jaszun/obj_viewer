#include "FileReader/Nodes/DoubleVectorNode.h"

void DoubleVectorNode::handleData(std::vector<std::string> splittedLine)
{
    std::cout << "double\n";

    std::vector<double> doubleArray;

    for (int i = 1; i < splittedLine.size(); i++)
    {
        doubleArray.push_back(std::stod(splittedLine.at(i)));

        std::cout << doubleArray.at(i - 1) << "\n";
    }
}