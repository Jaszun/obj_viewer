#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "InputManager.h"
#include "FileReader.h"

class App
{
private:
    Renderer renderer = nullptr; // <- to be changed;
    InputManager inputManager = nullptr;
    FileReader fileReader;

    std::string appName;

    int width;
    int height;

    bool isRunning = false;

    GLFWwindow *windowHandle;
    double timeElapsed{};

    void Init();

    void FetchInput();
    void Update();
    void Render();

public:
    App(int width, int height, std::string appName);
    ~App();

    void Run();
};
