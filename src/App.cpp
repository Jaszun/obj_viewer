#include "App.h"

App::App(int width, int height, std::string appName) : width(width), height(height), appName(appName) 
{
    
}

App::~App() {}

void App::Init()
{
    // m_Renderer.init();

    isRunning = true;

    std::cout << "App " << appName << " works!" << std::endl;
}

void App::Run()
{
    while (isRunning)
    {
        FetchInput();
        Update();
        Render();
    }
}

void App::FetchInput()
{
    std::cout << "Fetching..." << std::endl;
}

void App::Update()
{
    std::cout << "Updatting..." << std::endl;
}

void App::Render()
{
    std::cout << "Rendering..." << std::endl;

    isRunning = false;
}