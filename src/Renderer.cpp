#include "Renderer.h"

// temp
#include <cmath>

Renderer::Renderer(GLFWwindow* window) : windowHandle(window)
{
}

Renderer::~Renderer()
{
}

void Renderer::Draw(double time)
{
  glClearColor((cos(time) + 1) / 2, 0.f, (sin(time) + 1) /2, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
