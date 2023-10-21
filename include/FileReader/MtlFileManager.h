#pragma once

#include <iostream>
#include <array>
#include <string>

#include <glm/vec3.hpp>

#include "FileManager.h"

#include "shared/MaterialLibrary.h"

class MtlFileManager: public FileManager
{
private:
    std::shared_ptr<Material> currentMaterial = nullptr;

    glm::vec3 GetGlmVec3(std::vector<std::string> splittedLine);
    float GetFloat(std::vector<std::string> splittedLine);
    int GetInt(std::vector<std::string> splittedLine);

    void SaveMaterial();
public:
    const std::string commentToken = "#";
    MaterialLibrary materialLibrary;

    MtlFileManager(std::string fileName);

    void Init();
    void HandleData(std::string token, std::vector<std::string> splittedLine);
    void OnFileLoaded();
};