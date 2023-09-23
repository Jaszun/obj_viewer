#include "App.h"

App::App(int width, int height, std::string appName) : width(width), height(height), appName(appName) 
{
    
}

App::~App() 
{
    std::cout << "Cleaning up!" << std::endl;
    glfwDestroyWindow(windowHandle);
    glfwTerminate();
}

void App::Init()
{
    // initialize glfw and try to create a window
    if (glfwInit())
        windowHandle = glfwCreateWindow(width, height, appName.c_str(), NULL, NULL);

    // if window creation was successful make it into current context and load opengl functions
    if (windowHandle)
    {
        glfwMakeContextCurrent(windowHandle);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        // glfwSetWindowUserPointer(windowHandle, this);

        renderer = Renderer(windowHandle);

        eventListener = WindowEventListener(windowHandle);
        eventListener.Init();

        isRunning = true;
    }

    std::cout << "App " << appName << " works!" << '\n';
}

void App::Run()
{
    Init();

    while (isRunning && !glfwWindowShouldClose(windowHandle))
    {
        timeElapsed = glfwGetTime();

        FetchInput();
        Update();
        Render();

        glfwSwapBuffers(windowHandle);
    }

    std::cout << "Run function ended!" << '\n';
}

void App::FetchInput()
{
    eventListener.PollEvents();

    if (eventListener.isScrolled)
    {
        std::cout << "There's some scrolling here waiting to be handled\n";
    }

    if (eventListener.isDragged)
    {
        std::cout << "This is not even implemented yet\n";
    }

    if (eventListener.isFileDropped)
    {
        std::cout << "Someone's just dropped a file(s)\n";
    }

    if (eventListener.isWindowResized)
    {
        std::cout << "The window has been resized\n";
    }
}

void App::Update()
{
    // std::cout << "Updating..." << '\n';
}

void App::Render()
{
    renderer.Draw(timeElapsed);
}