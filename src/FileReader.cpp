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
    fileExtension = path.substr(path.find_last_of('.') + 1);

    if (fileExtension == "obj")
        return new ObjFileManager();
    else if (fileExtension == "mtl")
        return new MtlFileManager();
    
    return nullptr;
}

void FileReader::ReadFile(std::string path)
{
    fileRead = false;

    fileManager = GetFileManager(path);

    if (!fileManager)
    {
        std::cout << "File not recognized\n";
        return;
    }

    fileManager->Init();

    std::ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        std::cout << "Couldn't open file\n";
        return;
    }
        
    std::string line;

    std::cout << "Loading file...\n";

    while (std::getline(file, line))
    {
        if (line.length() > 0)
        {
            std::vector<std::string> splittedLine = SplitLine(line, ' ');

            std::string token = splittedLine.at(0);

            if (token != fileManager->commentToken)
            {
                fileManager->HandleData(token, splittedLine);
            }
        }
    }

    std::cout << "Finished loading!\n";

    file.close();

    fileManager->OnFileLoaded();

    fileRead = true;
}