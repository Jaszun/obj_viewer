#pragma once

#include <iostream>
#include <glm/vec3.hpp>

/**
 * stores data to be submited to the shader
*/
class Material
{
private:
    /* data */
public:
    std::string name;

    float specularExponent; // Ns
    glm::vec3 ambient; // Ka
    glm::vec3 diffuse; // Kd
    glm::vec3 specular; // Ks
    glm::vec3 emissiveCoeficient; // Ke
    float opticalDensity; // Ni
    float dissolve; // d / Tr (Tr = 1 - d)
    int illuminationModel; // illum (enum code)
    glm::vec3 transmissionFilterColorRGB; // Tf
    glm::vec3 transmissionFilterColorCIEXYZ; // Tf xyz

    // texture paths

    std::string ambientTextureMap; // map_Ka
    std::string diffuseTextureMap; // map_Kd
    std::string specularColorTextureMap; // map_Ks
    std::string specularHighlightTextureMap; // map_Ns
    std::string alphaTextureMap; // map_d
    std::string bumpMap; // map_bump / bump
    std::string displacementMap; // disp
    std::string stencilDecalTexture; // decal

    Material(/* args */);
    ~Material();
};

