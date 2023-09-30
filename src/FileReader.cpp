#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

std::vector<std::string> FileReader::SplitLine(std::string line, char separator)
{
    std::vector<std::string> splittedLine;

    std::string temp = "";

    int index = 0;
   
    for(int i = 0; i < line.length(); i++)
    {
        if (line[i] != separator)
            temp += line[i];
        
        else
        {
            splittedLine.push_back(temp);
            temp = "";
        }
    }

    splittedLine.push_back(temp);

    return splittedLine;
}

Node* getNodeBySymbol(std::string symbol)
{
    // std::cout << symbol << "\n";

    if (symbol == "v" || symbol == "vn" || symbol == "vt")
        return new DoubleVectorNode();
    
    return new StringNode();
}

void FileReader::ReadFile(std::string path)
{
    std::ifstream file;
    
    file.open(path);

    if(file.is_open())
    {
        // create manager for file type

        std::string line;

        std::string prevSymbol = "";

        Node* node;

        while(std::getline(file, line))
        {
            if (line.length() > 0)
            {
                std::vector<std::string> splittedLine = SplitLine(line, ' ');

                std::string symbol = splittedLine.at(0);

                if (symbol != "#")
                {
                    if (symbol != prevSymbol)
                        node = getNodeBySymbol(symbol);

                    node->handleData(splittedLine);
                }

                prevSymbol = symbol;
            }
        }
        
        delete node;

        file.close();
    }
}