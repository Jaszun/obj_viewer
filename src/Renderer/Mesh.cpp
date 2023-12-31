#include "Renderer/Mesh.h"

Mesh::Mesh(std::vector<Vertex> &&vertices)
    : vertices(vertices)
{
    vao = std::make_unique<VAO>();
    vbo = std::make_unique<VBO>(vertices.data(), std::size(vertices));
    vao->Bind();
    vao->AddBuffer(*vbo);
    vao->Unbind();
}

Mesh::~Mesh()
{
    std::cout << "Mesh culled\n";
}

void Mesh::Draw()
{
    vao->Bind();
    glDrawArrays(GL_TRIANGLES, 0, std::size(vertices));
    vao->Unbind();
}
