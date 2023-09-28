#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer/Shader.h"

class Renderer
{
private:
  GLFWwindow *windowHandle;

  Shader shader{};

public:
  Renderer(GLFWwindow *window);
  ~Renderer();

  void SetShader();
  // temporary - docelowo tutaj będą trafiać modele i będzie to wyglądać zdecydowanie inaczej
  void RegisterObject();
  void UnregisterObject();
  void Draw(double time);
};
