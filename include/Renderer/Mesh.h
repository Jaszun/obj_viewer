#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "shared/Vertex.h"
#include "VAO.h"
#include "VBO.h"
#include "Material.h"
/*
TODO
[] store verticies
[] store material
*/

/**
 * Stores the vertices and reference to material
 */
class Mesh
{
private:
    std::unique_ptr<Material> material;
    std::vector<Vertex> vertices;
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;

public:
    Mesh(std::vector<Vertex> &&vertices, std::string &&materialName);
    ~Mesh();

    void Draw();
};
