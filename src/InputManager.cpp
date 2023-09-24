#include "InputManager.h"

InputManager::InputManager(GLFWwindow* window) : windowHandle(window)
{
}

InputManager::~InputManager()
{
}

void InputManager::Init()
{
    glfwSetWindowUserPointer(windowHandle, this);

    // binding callbacks

    glfwSetFramebufferSizeCallback(windowHandle, [](GLFWwindow* window, int width, int height)
        {
            InputManager* manager = reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));

            if (manager)
                manager->OnResize(width, height);
        }
    );
    glfwSetDropCallback(windowHandle, [](GLFWwindow* window, int count, const char** paths)
        {
            InputManager* manager = reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));

            if (manager)
                manager->OnDrop(count, paths);
        }
    );
    glfwSetScrollCallback(windowHandle, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            InputManager* manager = reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));

            if (manager)
                manager->OnScroll(xoffset, yoffset);
        }
    );
    glfwSetMouseButtonCallback(windowHandle, [](GLFWwindow* window, int button, int action, int mods)
        {
            InputManager* manager = reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));

            if (manager)
            {
                if (action == GLFW_PRESS)
                {
                    if (!manager->mLeftMouseButtonPressed && !manager->mRightMouseButtonPressed)
                    {
                        double x, y;

                        glfwGetCursorPos(window, &x, &y);

                        manager->dragStartPoint.xOffset = x;
                        manager->dragStartPoint.yOffset = y;
                    }

                    if (button == GLFW_MOUSE_BUTTON_LEFT && !manager->mRightMouseButtonPressed)
                        manager->mLeftMouseButtonPressed = true;

                    else if (button == GLFW_MOUSE_BUTTON_RIGHT && !manager->mLeftMouseButtonPressed)
                        manager->mRightMouseButtonPressed = true;
                }

                else
                {
                    if (button == GLFW_MOUSE_BUTTON_LEFT)
                        manager->mLeftMouseButtonPressed = false;

                    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
                        manager->mRightMouseButtonPressed = false;
                }
            }
        }
    );
    glfwSetCursorPosCallback(windowHandle, [](GLFWwindow* window, double xpos, double ypos)
        {
            InputManager* manager = reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));

            if (manager)
            {
                if (manager->mLeftMouseButtonPressed || manager->mRightMouseButtonPressed)
                    manager->OnDrag(xpos, ypos);
            }
        }
    );
}

void InputManager::ResetEventBools()
{
    isScrolled = isLeftDragged = isRightDragged = isWindowResized = isFileDropped = false;
}

// Events handling

void InputManager::PollEvents()
{
    ResetEventBools();

    glfwPollEvents();
}

// Mouse listeners

void InputManager::OnScroll(double xoffset, double yoffset)
{
    isScrolled = true;

    scroll.xOffset = xoffset;
    scroll.yOffset = yoffset;
}

void InputManager::OnDrag(double xpos, double ypos)
{
    if (mLeftMouseButtonPressed)
        isLeftDragged = true;
    else
        isRightDragged = true;

    dragCurrentPoint.xOffset = xpos - dragStartPoint.xOffset;
    dragCurrentPoint.yOffset = dragStartPoint.yOffset - ypos;
}

// Window listeners

void InputManager::OnResize(int width, int height)
{
    isWindowResized = true;

    window.newWidth = width;
    window.newHeight = height;
}

// Misc listeners

void InputManager::OnDrop(int count, const char** paths)
{
    isFileDropped = true;

    droppedFiles.count = count;
    droppedFiles.paths = new std::string[count];

    for (int i = 0; i < count; i++)
    {
        droppedFiles.paths[i] = paths[i];
    }
}