#pragma once

#include <iostream>
#include <vector>

#include "Renderer/Mesh.h"
#include "Renderer/Shader.h"
/*
TODO:
[] store meshes
[] register meshes
*/

/**
 * this class is supposed to handle the interaction between meshes and renderer
 */
class Object
{
private:
    std::vector<Mesh> meshes;

public:
    Object(std::vector<Mesh> &&meshes);
    ~Object();
    void Draw(Shader *shader);
};
