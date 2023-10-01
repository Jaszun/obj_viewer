#include "FileReader/Nodes/DoubleVectorNode.h"

void DoubleVectorNode::handleData(std::vector<std::string> splittedLine)
{
    std::cout << "double\n";

    std::vector<double> doubleVector;

    for (int i = 1; i < splittedLine.size(); i++)
    {
        doubleVector.push_back(std::stod(splittedLine.at(i)));

        std::cout << doubleVector.at(i - 1) << "\n";
    }

    data = doubleVector;
}