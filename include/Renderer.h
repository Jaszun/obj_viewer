#pragma once

#include <deque>
#include <iostream>
#include <memory>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "Renderer/Shader.h"
#include "Renderer/Object.h"

class Renderer
{
private:
  GLFWwindow *windowHandle;

  std::shared_ptr<Shader> shader;
  std::vector<std::shared_ptr<Object>> objects;

public:
  Renderer(GLFWwindow *window);
  ~Renderer();

  void SetShader();
  void Init();
  // temporary - docelowo tutaj będą trafiać modele i będzie to wyglądać zdecydowanie inaczej
  void RegisterObject();
  void UnregisterObject();
  void Draw(double time);
};
