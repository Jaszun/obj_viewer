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
    const enum TokenSymbol
    {
        newmtl,
        Ns,
        Ka,
        Kd,
        Ks,
        Ke,
        Ni,
        d,
        Tr,
        illum,
        Tf,
        map_Ka,
        map_Kd,
        map_Ks,
        map_Ns,
        map_d,
        map_bump,
        bump,
        disp,
        decal
    };

    const std::map<std::string, TokenSymbol> tokenMap =
    {
        { "newmtl", newmtl },
        { "Ns", Ns },
        { "Ka", Ka },
        { "Kd", Kd },
        { "Ks", Ks },
        { "Ke", Ke },
        { "Ni", Ni },
        { "d", d },
        { "Tr", Tr },
        { "illum", illum },
        { "Tf", Tf },
        { "map_Ka", map_Ka },
        { "map_Kd", map_Kd },
        { "map_Ks", map_Ks },
        { "map_Ns", map_Ns },
        { "map_d", map_d },
        { "map_bump", map_bump },
        { "bump", bump },
        { "disp", disp },
        { "decal", decal }
    };

    std::shared_ptr<Material> currentMaterial = nullptr;

    glm::vec3 GetGlmVec3(std::vector<std::string> splittedLine);
    glm::vec3 GetGlmVec3ForTfXYZ(std::vector<std::string> splittedLine);
    float GetFloat(std::vector<std::string> splittedLine);
    int GetInt(std::vector<std::string> splittedLine);

    std::string MakePathTo(std::vector<std::string> splittedLine);

    void SaveMaterial();
public:
    const std::string commentToken = "#";
    MaterialLibrary materialLibrary;

    MtlFileManager(std::string fileName, std::string dirPath);

    void Init();
    void HandleData(std::string token, std::vector<std::string> splittedLine);
    void OnFileLoaded();
};