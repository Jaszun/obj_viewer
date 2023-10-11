#include "App.h"

// temp
void message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const *message, void const *user_param)
{
    auto const src_str = [source]()
    {
        switch (source)
        {
        case GL_DEBUG_SOURCE_API:
            return "API";
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            return "WINDOW SYSTEM";
        case GL_DEBUG_SOURCE_SHADER_COMPILER:
            return "SHADER COMPILER";
        case GL_DEBUG_SOURCE_THIRD_PARTY:
            return "THIRD PARTY";
        case GL_DEBUG_SOURCE_APPLICATION:
            return "APPLICATION";
        case GL_DEBUG_SOURCE_OTHER:
            return "OTHER";
        }
    }();

    auto const type_str = [type]()
    {
        switch (type)
        {
        case GL_DEBUG_TYPE_ERROR:
            return "ERROR";
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            return "DEPRECATED_BEHAVIOR";
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            return "UNDEFINED_BEHAVIOR";
        case GL_DEBUG_TYPE_PORTABILITY:
            return "PORTABILITY";
        case GL_DEBUG_TYPE_PERFORMANCE:
            return "PERFORMANCE";
        case GL_DEBUG_TYPE_MARKER:
            return "MARKER";
        case GL_DEBUG_TYPE_OTHER:
            return "OTHER";
        }
    }();

    auto const severity_str = [severity]()
    {
        switch (severity)
        {
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            return "NOTIFICATION";
        case GL_DEBUG_SEVERITY_LOW:
            return "LOW";
        case GL_DEBUG_SEVERITY_MEDIUM:
            return "MEDIUM";
        case GL_DEBUG_SEVERITY_HIGH:
            return "HIGH";
        }
    }();
    std::cout << src_str << ", " << type_str << ", " << severity_str << ", " << id << ": " << message << '\n';
}

App::App(int width, int height, std::string appName) : width(width), height(height), appName(appName)
{
}

App::~App()
{
    std::cout << "Cleaning up!" << std::endl;
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

        // glEnable(GL_DEBUG_OUTPUT);
        // glDebugMessageCallback(message_callback, nullptr);

        renderer = Renderer(windowHandle);
        renderer.SetShader();
        renderer.Init();

        inputManager = InputManager(windowHandle);
        inputManager.Init();

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

    // renderer.~Renderer();
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

    if (inputManager.isFileDropped)
    {
        std::cout << "Someone's just dropped a file(s)\n";
        std::cout << "Num of files: " << inputManager.droppedFiles.count << ", Paths:\n";

        for (int i = 0; i < inputManager.droppedFiles.count; i++)
        {
            std::cout << i + 1 << ". " << inputManager.droppedFiles.paths[i] << "\n";
        }
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
    // std::cout << "Updating..." << '\n';
}

void App::Render()
{
    if (inputManager.isWindowResized)
        renderer.Resize(inputManager.window.newWidth, inputManager.window.newHeight);

    renderer.Draw(timeElapsed);
}
