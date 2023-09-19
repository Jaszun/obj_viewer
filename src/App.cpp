#include "App.h"

// na razie callbacki, potem będzie można to fetchować jednak
void drop_callback(GLFWwindow* window, int count, const char** paths) {
    for (int i = 0;  i < count;  i++)
    {
       ((App*) glfwGetWindowUserPointer(window))->HandlePath(paths[i]);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

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
    // m_Renderer.init();

    // initialize glfw and try to create a window
    if (glfwInit())
        windowHandle = glfwCreateWindow(width, height, appName.c_str(), NULL, NULL);

    // if window creation was successful make it into current context and load opengl functions
    if (windowHandle)
    {
        glfwMakeContextCurrent(windowHandle);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        glfwSetWindowUserPointer(windowHandle, this);
        glfwSetDropCallback(windowHandle, drop_callback);
        glfwSetFramebufferSizeCallback(windowHandle, framebuffer_size_callback);
        renderer = Renderer(windowHandle);

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
    glfwPollEvents();
    // std::cout << "Fetching..." << '\n';
}

void App::HandlePath(const char* path)
{
    std::cout << path << "\n";
}

void App::Update()
{
    // std::cout << "Updating..." << '\n';
}

void App::Render()
{
    renderer.Draw(timeElapsed);
    // std::cout << "Rendering..." << '\n';

    // isRunning = false;
}