#include "Renderer.h"

// temp
#include <cmath>

Renderer::Renderer(GLFWwindow *window) : windowHandle(window)
{
}

void Renderer::Init()
{
  std::vector<Mesh> triangleMeshes;

  std::vector<Vertex> vertices{
      {glm::vec3(-0.8, -0.5, 0.5), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-0.2, -0.5, 0.5), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-0.5, 0.1, 0.5), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)}};

  std::vector<Vertex> vertices2{
      {glm::vec3(0.2, -0.5, -0.5), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(0.8, -0.5, -0.5), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(0.5, 0.1, -0.5), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)}};

  triangleMeshes.reserve(2);
  triangleMeshes.emplace_back(std::move(vertices));
  triangleMeshes.emplace_back(std::move(vertices2));

  objects.emplace_back(std::move(triangleMeshes));
}

Renderer::~Renderer()
{
}

void Renderer::SetShader()
{
  shader = Shader("./shaders/VertexShader.vert", "./shaders/FragmentShader.frag");
}

void Renderer::Draw(double time)
{

  glClearColor((cos(time) + 1) / 2, 0.f, (sin(time) + 1) / 2, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  shader.Use();

  for (int i = 0; i < objects.size(); i++)
  {
    objects[i].Draw(&shader);
  }

  // for (Object object : objects)
  // object.Draw();

  // glDrawArrays(GL_TRIANGLES, 0, 3);
}
