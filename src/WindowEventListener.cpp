#include "WindowEventListener.h"

//
// Wszystko to jest tymczasowe rozwiązanie jakby co
//

// na razie callbacki, potem będzie można to fetchować jednak
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    std::cout << "Scrolling " << xoffset << " " << yoffset << std::endl;
}

void drop_callback(GLFWwindow* window, int count, const char** paths) {
    for (int i = 0;  i < count;  i++)
    {
       std::cout << paths[i] << "\n";
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}



WindowEventListener::WindowEventListener(GLFWwindow* window) : windowHandle(window)
{
}

WindowEventListener::~WindowEventListener()
{
}

// Events handling

void WindowEventListener::PollEvents()
{
    glfwPollEvents();

    OnScroll();
    OnDrag();
    OnResize();
    OnDrop();
}

// Mouse listeners

void WindowEventListener::OnScroll()
{
    glfwSetScrollCallback(windowHandle, scroll_callback);
}

void WindowEventListener::OnDrag()
{
    // TODO
}

// Window listeners

void WindowEventListener::OnResize()
{
    glfwSetFramebufferSizeCallback(windowHandle, framebuffer_size_callback);
}

// Misc listeners

void WindowEventListener::OnDrop()
{
    glfwSetDropCallback(windowHandle, drop_callback);
}