#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

class App
{
private:
    // 3DObject m_Object;
    Renderer renderer = nullptr; // <- idk chyba powinno się jakoś inaczej

    std::string appName;

    int width;
    int height;

    bool isRunning = false;

    // value unexpected replace with "windowHandle{}" to initialize with zero value
    GLFWwindow* windowHandle;
    double timeElapsed{};
    
    void Init();

    void FetchInput();
    void Update();
    void Render();
public:
    App(int width, int height, std::string appName);
    ~App();

    void Run();
    void HandlePath(const char* path);
};
