#include "Renderer.h"

// temp
#include <cmath>

#define FOV 70.0f

Renderer::Renderer(GLFWwindow *window) : windowHandle(window)
{
}

void Renderer::Init()
{
  glEnable(GL_DEPTH_TEST);

  int width, height;
  glfwGetWindowSize(windowHandle, &width, &height);
  // matrices setup
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
  //
  projection = glm::perspective(FOV, (float)width / (float)height, 0.1f, 100.0f);

  // object setup
  std::vector<std::shared_ptr<Mesh>>
      triangleMeshes;

  std::vector<Vertex> vertices{
      {glm::vec3(-0.8, -0.5, 0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-0.2, -0.5, 0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-0.5, 0.1, 0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)}};

  std::vector<Vertex> vertices2{
      {glm::vec3(0.2, -0.5, 0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(0.8, -0.5, 0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(0.5, 0.1, 0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)}};

  std::vector<Vertex> vertices3{
      {glm::vec3(-0.3, -0.5, -0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(0.3, -0.5, -0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(0.0, 0.1, -0.2), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)}};

  // triangleMeshes.reserve(2);
  triangleMeshes.emplace_back(std::make_shared<Mesh>(std::move(vertices)));
  triangleMeshes.emplace_back(std::make_shared<Mesh>(std::move(vertices3)));
  triangleMeshes.emplace_back(std::make_shared<Mesh>(std::move(vertices2)));

  std::vector<std::shared_ptr<Mesh>> cubeMeshes;

  std::vector<Vertex> vericesForCube{
      {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)},
      {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(.0, .0, .0), glm::vec2(.0, .0)}};

  cubeMeshes.emplace_back(std::make_shared<Mesh>(std::move(vericesForCube)));

  // multiple meshes test
  objects.emplace_back(std::make_shared<Object>(std::move(triangleMeshes)));

  // default cube
  // objects.emplace_back(std::make_shared<Object>(std::move(cubeMeshes)));
}

void Renderer::Resize(const int &width, const int &height)
{
  projection = glm::perspective(FOV, (float)width / (float)height, 0.1f, 100.0f);
}

Renderer::~Renderer()
{
}

void Renderer::SetShader()
{
  shader = std::make_shared<Shader>("./shaders/VertexShader.vert", "./shaders/FragmentShader.frag");
}

void Renderer::Draw(double time)
{
  double timeDiff = time - timeElapsed;

  // MULTI COLOUR FUN
  // glClearColor((cos(time) + 1) / 2, 0.f, (sin(time) + 1) / 2, 1.0f);
  glClearColor(1.0f / 255, 22.0f / 255, 39.0f / 255, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  shader->Use();

  shader->SetUniformMat4(view, "view");
  shader->SetUniformMat4(projection, "projection");

  for (const auto &object : objects)
  {
    object->TestRotate(45.0f * timeDiff);
    object->Draw(shader);
  }

  timeElapsed = time;
  // for (Object object : objects)
  // object.Draw();

  // glDrawArrays(GL_TRIANGLES, 0, 3);
}
