#pragma once

#include <deque>
#include <iostream>
#include <memory>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "Renderer/Shader.h"
#include "Renderer/Object.h"

#include "FileReader.h"

class Renderer
{
private:
  GLFWwindow *windowHandle;

  std::shared_ptr<Shader> shader;
  std::vector<std::shared_ptr<Object>> objects;

  // matrices
  glm::mat4 projection{1.0f};
  glm::mat4 view{1.0f};

  double timeElapsed = 0;

public:
  Renderer(GLFWwindow *window);
  ~Renderer();

  void SetShader();
  void Init();
  // temporary - docelowo tutaj będą trafiać modele i będzie to wyglądać zdecydowanie inaczej
  void RegisterObject();
  void UnregisterObject();
  void Draw(double time);
  void Resize(const int &width, const int &height);
};
