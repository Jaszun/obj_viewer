#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
private:
  GLFWwindow* windowHandle;
public:
  Renderer(GLFWwindow* window);
  ~Renderer();
  
  // temporary - docelowo tutaj będą trafiać modele i będzie to wyglądać zdecydowanie inaczej
  void Draw(double time);
};

