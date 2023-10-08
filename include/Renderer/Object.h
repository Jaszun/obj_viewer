#pragma once

#include <iostream>
#include <memory>
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
    std::vector<std::shared_ptr<Mesh>> meshes;

public:
    Object(std::vector<std::shared_ptr<Mesh>> &&meshes);
    ~Object();
    void Draw(std::shared_ptr<Shader> &shader);
};
