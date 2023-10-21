#include "FileReader/MtlFileManager.h"

MtlFileManager::MtlFileManager(std::string fileName) : FileManager(fileName)
{
    materialLibrary.name = fileName;
}

void MtlFileManager::Init()
{
}

void MtlFileManager::HandleData(std::string token, std::vector<std::string> splittedLine)
{
    if (token == "newmtl")
    {
        if (currentMaterial)
            SaveMaterial();

        currentMaterial = std::make_unique<Material>();
        currentMaterial->name = splittedLine.at(1);
    }
    else if (token == "Ns")
        currentMaterial->specularExponent = GetFloat(splittedLine);
    else if (token == "Ka")
        currentMaterial->ambient = GetGlmVec3(splittedLine);
    else if (token == "Kd")
        currentMaterial->diffuse = GetGlmVec3(splittedLine);
    else if (token == "Ks")
        currentMaterial->specular = GetGlmVec3(splittedLine);
    else if (token == "Ke")
        currentMaterial->emissiveCoeficient = GetGlmVec3(splittedLine);
    else if (token == "Ni")
        currentMaterial->opticalDensity = GetFloat(splittedLine);
    else if (token == "d")
        currentMaterial->dissolve = GetFloat(splittedLine);
    else if (token == "illum")
        currentMaterial->illuminationModel = GetInt(splittedLine);
}

void MtlFileManager::OnFileLoaded()
{
    SaveMaterial();
}

void MtlFileManager::SaveMaterial()
{
    materialLibrary.materials.emplace_back(currentMaterial);

    std::cout << "Material: " << currentMaterial->name << " saved!\n";
}

// data mamaging functions

glm::vec3 MtlFileManager::GetGlmVec3(std::vector<std::string> splittedLine)
{
    return glm::vec3
        (
            std::stof(splittedLine.at(1)),
            std::stof(splittedLine.at(2)),
            std::stof(splittedLine.at(3))
        );
}

float MtlFileManager::GetFloat(std::vector<std::string> splittedLine)
{
    return std::stof(splittedLine.at(1));
}

int MtlFileManager::GetInt(std::vector<std::string> splittedLine)
{
    return std::stoi(splittedLine.at(1));
}