#pragma once

#include <iostream>
#include <vector>

#include "Vertex.h"
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
    VAO *vao;
    VBO *vbo;

public:
    Mesh(std::vector<Vertex> &&vertices);
    ~Mesh();
    void Draw();
};
