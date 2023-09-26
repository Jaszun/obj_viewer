#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

void FileReader::ReadFile(std::string path)
{
    std::ifstream file;
    file.open(path);

    if (file.is_open())
    {
        std::string line;

        while (std::getline(file, line))
        {
            std::cout << line << "\n";
        }

        file.close();
    }
}