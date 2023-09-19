#pragma once

#include <iostream>

class App
{
private:
    // 3DObject m_Object;
    // Renderer m_Renderer;

    std::string appName;

    int width;
    int height;

    bool isRunning;
    
public:
    App(int width, int height, std::string appName);
    ~App();

    void Init();
    void Run();

    void FetchInput();
    void Update();
    void Render();
};
