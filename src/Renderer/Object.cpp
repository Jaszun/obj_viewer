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
        shader->SetUniformMat4(model, "model");

        if (i++ % 2)
            shader->SetUniformVec3(glm::vec3(1.0f, 51.0f / 255, 102.0f / 255), "u_Color");
        // shader->UseMaterial(mesh.GetMaterial());
        else
            shader->SetUniformVec3(glm::vec3(46.0 / 255, 196.0 / 255, 182.0 / 255), "u_Color");

        mesh->Draw();
    }
}

void Object::TestRotate(float value)
{
    model = glm::rotate(model, glm::radians(value), glm::vec3(0.0f, 1.0f, 0.0f));
}
