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
        std::cout << "x offset: " << eventListener.Scroll.xOffset << " y offset: " << eventListener.Scroll.yOffset << "\n";
    }

    if (eventListener.isDragged)
    {
        std::cout << "This is not fully implemented yet\n";

        std::cout << eventListener.Drag.x << " " << eventListener.Drag.y << "\n";
    }

    if (eventListener.isFileDropped)
    {
        std::cout << "Someone's just dropped a file(s)\n";
        std::cout << "Num of files: " << eventListener.DroppedFiles.count << ", Paths:\n";
        
        for (int i = 0; i < eventListener.DroppedFiles.count; i++) {
            std::cout << i + 1 << ". " << eventListener.DroppedFiles.paths[i] << "\n";
        }
    }

    if (eventListener.isWindowResized)
    {
        width = eventListener.Window.newWidth;
        height = eventListener.Window.newHeight;

        std::cout << "The window has been resized\n";
        std::cout << "New size: " << width << "x" << height << "\n";

        glViewport(0, 0, width, height);
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