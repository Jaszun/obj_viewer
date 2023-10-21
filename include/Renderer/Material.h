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
    float dissolve; // d
    int illuminationModel; // illum (enum code)

    Material(/* args */);
    ~Material();
};

