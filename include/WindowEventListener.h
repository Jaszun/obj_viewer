#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowEventListener // InputManager
{
private:
    GLFWwindow* windowHandle;

    bool mRightMouseButtonPressed = false;
    bool mLeftMouseButtonPressed = false;
    
    void resetEventBools();
public:
    WindowEventListener(GLFWwindow* windowHandle);
    ~WindowEventListener();

    void Init();

    // Functions for handling events

    void PollEvents();

    // Mouse listeners
    void OnScroll(double xoffset, double yoffset);
    void OnDrag(double xpos, double ypos);

    // Window listeners
    void OnResize(int width, int height);

    // Misc listeners
    void OnDrop(int count, const char** paths);

    bool isScrolled;
    bool isDragged;
    bool isWindowResized;
    bool isFileDropped;

    // na razie wrzucę tutaj deklaracje struktur
    // jeśli uznamy, że trzymanie danych w ten sposób nam odpowiada, zrobimy to bardziej po ludzku

    struct
    {
        double xOffset;
        double yOffset;
    } Scroll;

    // temp - do zweryfikowania po zaimplementowaniu
    struct
    {
        double x;
        double y;
    } Drag;

    struct
    {
        int count;
        std::string* paths;
    } DroppedFiles;

    struct
    {
        int newWidth;
        int newHeight;
    } Window;
};