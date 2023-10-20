#include "FileReader/FileManager/MtlFileManager.h"

MtlFileManager::MtlFileManager() : FileManager()
{
}

void MtlFileManager::Init()
{
    converters = 
    {
        new GlmVec3Converter({"Ka", "Kd", "Ks"}),
        new StringConverter({"v", "vn"}),
    };
}

void ObjFileManager::SaveData(std::string token, Converter* converter)
{

}

void ObjFileManager::InterpretData()
{

}