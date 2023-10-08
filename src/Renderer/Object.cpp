#include "Renderer/Object.h"

Object::Object(std::vector<std::shared_ptr<Mesh>> &&meshes)
    : meshes(std::move(meshes))
{
}

Object::~Object()
{
    std::cout << "Object culled\n";
}

void Object::Draw(std::shared_ptr<Shader> &shader)
{
    int i = 0;
    for (const auto &mesh : meshes)
    {
        mesh->Draw();
        if (i++ % 2)
            shader->SetUniformVec3(glm::vec3(1.0f, 1.0f, 0.0f), "u_Color");
        // shader->UseMaterial(mesh.GetMaterial());
        else
            shader->SetUniformVec3(glm::vec3(0.0, 1.0, 0.0), "u_Color");
    }
}
