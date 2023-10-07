#include "Renderer/Object.h"

Object::Object(std::vector<Mesh> &&meshes)
    : meshes(std::move(meshes))
{
}

Object::~Object()
{
    std::cout << "Object culled\n";
}

void Object::Draw(Shader *shader)
{
    for (int i = 0; i < std::size(meshes); i++)
    {
        meshes[i].Draw();
        if (i % 2)
            shader->SetUniformVec3(glm::vec3(0.0, 1.0, 0.0), "u_Color");
            // shader->UseMaterial(mesh.GetMaterial());
        else
            shader->SetUniformVec3(glm::vec3(1.0, 1.0, 0.0), "u_Color");
    }
}
