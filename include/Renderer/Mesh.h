#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "common/Vertex.h"
#include "VAO.h"
#include "VBO.h"
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
    std::vector<Vertex> vertices;
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;

public:
    Mesh(std::vector<Vertex> &&vertices);
    ~Mesh();
    void Draw();
};
