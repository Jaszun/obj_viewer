#include "WindowEventListener.h"

//
// Wszystko to jest tymczasowe rozwiązanie jakby co
//

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

    if (listener)
        listener->OnScroll(xoffset, yoffset);
}

void drop_callback(GLFWwindow* window, int count, const char** paths)
{
    WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

    if (listener)
        listener->OnDrop(count, paths);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

    if (listener)
        listener->OnResize(width, height);
}



WindowEventListener::WindowEventListener(GLFWwindow* window) : windowHandle(window)
{
}

WindowEventListener::~WindowEventListener()
{
}

void WindowEventListener::Init()
{
    glfwSetWindowUserPointer(windowHandle, this);

    glfwSetFramebufferSizeCallback(windowHandle, framebuffer_size_callback);
    glfwSetDropCallback(windowHandle, drop_callback);
    glfwSetScrollCallback(windowHandle, scroll_callback);
}

void WindowEventListener::resetEventBools()
{
    isScrolled = false;
    isDragged = false;
    isWindowResized = false;
    isFileDropped = false;
}

// Events handling

void WindowEventListener::PollEvents()
{
    resetEventBools();

    glfwPollEvents();
}

// Mouse listeners

void WindowEventListener::OnScroll(double xoffset, double yoffset)
{
    isScrolled = true;
}

void WindowEventListener::OnDrag()
{
    isDragged = true;

    // TODO
}

// Window listeners

void WindowEventListener::OnResize(int width, int height)
{
    isWindowResized = true;

    glViewport(0, 0, width, height);
}

// Misc listeners

void WindowEventListener::OnDrop(int count, const char** paths)
{
    isFileDropped = true;

    for (int i = 0;  i < count;  i++)
    {
       std::cout << paths[i] << "\n";
    }
}