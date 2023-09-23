#include "WindowEventListener.h"

WindowEventListener::WindowEventListener(GLFWwindow* window) : windowHandle(window)
{
}

WindowEventListener::~WindowEventListener()
{
}

void WindowEventListener::Init()
{
    glfwSetWindowUserPointer(windowHandle, this);

    // binding callbacks

    glfwSetFramebufferSizeCallback(windowHandle, [](GLFWwindow* window, int width, int height)
        {
            WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

            if (listener)
                listener->OnResize(width, height);
        }
    );
    glfwSetDropCallback(windowHandle, [](GLFWwindow* window, int count, const char** paths)
        {
            WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

            if (listener)
                listener->OnDrop(count, paths);
        }
    );
    glfwSetScrollCallback(windowHandle, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

            if (listener)
                listener->OnScroll(xoffset, yoffset);
        }
    );
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

    Scroll.xOffset = xoffset;
    Scroll.yOffset = yoffset;
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

    Window.newWidth = width;
    Window.newHeight = height;
}

// Misc listeners

void WindowEventListener::OnDrop(int count, const char** paths)
{
    isFileDropped = true;

    // później ogarnę przekazywanie całej tablicy w jakiejś ludzkiej postaci
    DroppedFiles.count = count;
    DroppedFiles.path = std::string{paths[count - 1]};
}