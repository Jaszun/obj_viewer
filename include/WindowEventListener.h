#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowEventListener
{
private:
    GLFWwindow* windowHandle;
public:
    WindowEventListener(GLFWwindow* windowHandle);
    ~WindowEventListener();

    // Functions for handling events

    void PollEvents();

    // Mouse listeners
    void OnScroll();
    void OnDrag();

    // Window listeners
    void OnResize();

    // Misc listeners
    void OnDrop();
};