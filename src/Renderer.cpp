#include "Renderer.h"

// temp
#include <cmath>

Renderer::Renderer(GLFWwindow *window) : windowHandle(window)
{
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
  shader.Use();

  glClearColor((cos(time) + 1) / 2, 0.f, (sin(time) + 1) / 2, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glDrawArrays(GL_TRIANGLES, 0, 3);
}
