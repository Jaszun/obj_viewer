#include "App.h"

App::App(int width, int height, std::string appName) : width(width), height(height), appName(appName)
{
}

App::~App()
{
    std::cout << "Cleaning up!" << std::endl;
    // to be reimplemented
    // glfwDestroyWindow(windowHandle);
    // glfwTerminate();
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
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        renderer = Renderer(windowHandle);
        renderer.SetShader();
        renderer.Init();

        inputManager = InputManager(windowHandle);
        inputManager.Init();

        fileReader = FileReader();

        isRunning = true;
    }

    std::cout << "App " << appName << " works!" << '\n';
}

void App::Run()
{
    Init();
    // isRunning = false; // <- uncomment when testing app framework without looping
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
    inputManager.PollEvents();

    if (inputManager.isScrolled)
    {
        std::cout << "There's some scrolling here waiting to be handled\n";
        std::cout << "x offset: " << inputManager.scroll.xOffset << " y offset: " << inputManager.scroll.yOffset << "\n";
    }

    if (inputManager.isLeftDragged)
    {
        std::cout << "Dragged with LEFT mouse button\n";
        std::cout << inputManager.dragCurrentPoint.xOffset << " " << inputManager.dragCurrentPoint.yOffset << "\n";
    }

    if (inputManager.isRightDragged)
    {
        std::cout << "Dragged with RIGHT mouse button\n";
        std::cout << inputManager.dragCurrentPoint.xOffset << " " << inputManager.dragCurrentPoint.yOffset << "\n";
    }

    if (inputManager.isWindowResized)
    {
        width = inputManager.window.newWidth;
        height = inputManager.window.newHeight;

        std::cout << "The window has been resized\n";
        std::cout << "New size: " << width << "x" << height << "\n";

        glViewport(0, 0, width, height);
    }
}

void App::Update()
{
    if (inputManager.isFileDropped)
    {
        for (int i = 0; i < inputManager.droppedFiles.count; i++)
        {
            fileReader.ReadFile(inputManager.droppedFiles.paths[i]);

            if (fileReader.fileRead)
            {
                //TODO: Handle received data from fileReader.fileManager
            }
        }
    }
}

void App::Render()
{
    if (inputManager.isWindowResized)
        renderer.Resize(inputManager.window.newWidth, inputManager.window.newHeight);

    renderer.Draw(timeElapsed);
}
