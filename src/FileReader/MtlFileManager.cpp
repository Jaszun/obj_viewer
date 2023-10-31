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
    if (tokenMap.find(token) == tokenMap.end())
        return;
    
    switch(tokenMap.at(token))
    {
        case newmtl:
            if (currentMaterial)
                SaveMaterial();
            currentMaterial = std::make_unique<Material>();
            currentMaterial->name = splittedLine.at(1);
            break;
        case Ns:
            currentMaterial->specularExponent = GetFloat(splittedLine);
            break;
        case Ka:
            currentMaterial->ambient = GetGlmVec3(splittedLine);
            break;
        case Kd:
            currentMaterial->diffuse = GetGlmVec3(splittedLine);
            break;
        case Ks:
            currentMaterial->specular = GetGlmVec3(splittedLine);
            break;
        case Ke:
            currentMaterial->emissiveCoeficient = GetGlmVec3(splittedLine);
            break;
        case Ni:
            currentMaterial->opticalDensity = GetFloat(splittedLine);
            break;
        case d:
            currentMaterial->dissolve = GetFloat(splittedLine);
            break;
        case Tr:
            currentMaterial->dissolve = 1.0f - GetFloat(splittedLine);
            break;
        case illum:
            currentMaterial->illuminationModel = GetInt(splittedLine);
            break;
        case Tf:
            if (splittedLine.at(1) == "xyz")
                currentMaterial->transmissionFilterColorCIEXYZ = GetGlmVec3ForTfXYZ(splittedLine);
            else
                currentMaterial->transmissionFilterColorRGB = GetGlmVec3(splittedLine);
            break;
        case map_Ka:
            currentMaterial->ambientTextureMap = MakePathTo(splittedLine);
            break;
        case map_Kd:
            currentMaterial->diffuseTextureMap = MakePathTo(splittedLine);
            break;
        case map_Ks:
            currentMaterial->specularColorTextureMap = MakePathTo(splittedLine);
            break;
        case map_Ns:
            currentMaterial->specularHighlightTextureMap = MakePathTo(splittedLine);
            break;
        case map_d:
            currentMaterial->alphaTextureMap = MakePathTo(splittedLine);
            break;
        case map_bump:
        case bump:
            currentMaterial->bumpMap = MakePathTo(splittedLine);
            break;
        case disp:
            currentMaterial->displacementMap = MakePathTo(splittedLine);
            break;
        case decal:
            currentMaterial->stencilDecalTexture = MakePathTo(splittedLine);
            break;
    };
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