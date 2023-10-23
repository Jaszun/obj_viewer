#include "FileReader/MtlFileManager.h"

MtlFileManager::MtlFileManager(std::string fileName, std::string dirPath) : FileManager(fileName, dirPath)
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
    else if (token == "Tr")
        currentMaterial->dissolve = 1.0f - GetFloat(splittedLine);
    else if (token == "illum")
        currentMaterial->illuminationModel = GetInt(splittedLine);
    else if (token == "Tf")
    {
        if (splittedLine.at(1) == "xyz")
            currentMaterial->transmissionFilterColorCIEXYZ = GetGlmVec3ForTfXYZ(splittedLine);
        else
            currentMaterial->transmissionFilterColorRGB = GetGlmVec3(splittedLine);
    }
    else if (token == "map_Ka")
        currentMaterial->ambientTextureMap = MakePathTo(splittedLine);
    else if (token == "map_Kd")
        currentMaterial->diffuseTextureMap = MakePathTo(splittedLine);
    else if (token == "map_Ks")
        currentMaterial->specularColorTextureMap = MakePathTo(splittedLine);
    else if (token == "map_Ns")
        currentMaterial->specularHighlightTextureMap = MakePathTo(splittedLine);
    else if (token == "map_d")
        currentMaterial->alphaTextureMap = MakePathTo(splittedLine);
    else if (token == "map_bump" || token == "bump")
        currentMaterial->bumpMap = MakePathTo(splittedLine);
    else if (token == "disp")
        currentMaterial->displacementMap = MakePathTo(splittedLine);
    else if (token == "decal")
        currentMaterial->stencilDecalTexture = MakePathTo(splittedLine);
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

glm::vec3 MtlFileManager::GetGlmVec3ForTfXYZ(std::vector<std::string> splittedLine)
{
    // if only X is given, then Y and Z are the same as X
    if (splittedLine.size() == 3)
        return glm::vec3
            (
                std::stof(splittedLine.at(2)),
                std::stof(splittedLine.at(2)),
                std::stof(splittedLine.at(2))
            );

    return glm::vec3
        (
            std::stof(splittedLine.at(2)),
            std::stof(splittedLine.at(3)),
            std::stof(splittedLine.at(4))
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

std::string MtlFileManager::MakePathTo(std::vector<std::string> splittedLine)
{
    // splittedLine.size() - 1 <- allows to avoid texture options
    return dirPath + splittedLine.at(splittedLine.size() - 1);
}