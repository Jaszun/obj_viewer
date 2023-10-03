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
   
    for (int i = 0; i < line.length(); i++)
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

FileManager* FileReader::GetFileManager(std::string path)
{
    std::string fileExtension = path.substr(path.find_last_of('.') + 1);

    if (fileExtension == "obj")
        return new ObjFileManager();
    // if (fileExtension == "mtl")
    //     return new MtlFileManager();
    // ...
    
    return nullptr;
}

void FileReader::ReadFile(std::string path)
{
    FileManager* manager = GetFileManager(path);

    if (!manager)
    {
        std::cout << "Nie rozpoznano pliku\n";
        return;
    }

    manager->Init();

    std::ifstream file;
    
    file.open(path);

    if (file.is_open())
    {
        Node* node;

        std::string prevToken = "";
        std::string line;

        std::cout << "Loading file...\n";

        while (std::getline(file, line))
        {
            if (line.length() > 0)
            {
                std::vector<std::string> splittedLine = SplitLine(line, ' ');

                std::string token = splittedLine.at(0);

                if (token != "#")
                {
                    if (token != prevToken)
                        node = manager->GetNodeByToken(token);

                    if (node)
                    {
                        node->HandleData(splittedLine);
                        manager->SaveNodeData(token, node);
                    }
                }

                prevToken = token;
            }
        }

        std::cout << "Finished loading!\n";
        
        delete node;

        file.close();
    }

    manager->InterpretData();
}