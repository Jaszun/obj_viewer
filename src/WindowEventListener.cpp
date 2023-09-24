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
    glfwSetMouseButtonCallback(windowHandle, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

            if (listener)
            {
                // if ()
                // {
                    
                // }
                if (button == GLFW_MOUSE_BUTTON_LEFT)
                {
                    double x, y;

                    glfwGetCursorPos(window, &x, &y);

                    listener->dragStartPoint.xOffset = x;
                    listener->dragStartPoint.yOffset = y;

                    if (action == GLFW_PRESS)
                        listener->mLeftMouseButtonPressed = true;
                    else
                        listener->mLeftMouseButtonPressed = false;
                }

                else if (button == GLFW_MOUSE_BUTTON_RIGHT)
                {
                    if (action == GLFW_PRESS)
                        listener->mRightMouseButtonPressed = true;
                    else
                        listener->mRightMouseButtonPressed = false;
                }
            }
        }
    );
    glfwSetCursorPosCallback(windowHandle, [](GLFWwindow* window, double xpos, double ypos)
        {
            WindowEventListener* listener = reinterpret_cast<WindowEventListener*>(glfwGetWindowUserPointer(window));

            if (listener)
            {
                if (listener->mLeftMouseButtonPressed)
                    listener->OnDrag(xpos, ypos); //TODO: OnLeftDrag
                else if (listener->mRightMouseButtonPressed)
                    listener->OnDrag(xpos, ypos); //TODO: OnRightDrag
            }
        }
    );
}

void WindowEventListener::ResetEventBools()
{
    isScrolled = false;
    isDragged = false;
    isWindowResized = false;
    isFileDropped = false;
}

// Events handling

void WindowEventListener::PollEvents()
{
    ResetEventBools();

    glfwPollEvents();
}

// Mouse listeners

void WindowEventListener::OnScroll(double xoffset, double yoffset)
{
    isScrolled = true;

    scroll.xOffset = xoffset;
    scroll.yOffset = yoffset;
}

void WindowEventListener::OnDrag(double xpos, double ypos)
{
    //TODO: OnLeftDrag/OnRightDrag

    isDragged = true;

    dragCurrentPoint.xOffset = xpos - dragStartPoint.xOffset;
    dragCurrentPoint.yOffset = dragStartPoint.yOffset - ypos;
}

// Window listeners

void WindowEventListener::OnResize(int width, int height)
{
    isWindowResized = true;

    window.newWidth = width;
    window.newHeight = height;
}

// Misc listeners

void WindowEventListener::OnDrop(int count, const char** paths)
{
    isFileDropped = true;

    droppedFiles.count = count;
    droppedFiles.paths = new std::string[count];

    for (int i = 0; i < count; i++)
    {
        droppedFiles.paths[i] = paths[i];
    }
}