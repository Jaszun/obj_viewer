#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowEventListener // InputManager
{
private:
    GLFWwindow* windowHandle;
    
    void resetEventBools();
public:
    WindowEventListener(GLFWwindow* windowHandle);
    ~WindowEventListener();

    void Init();

    // Functions for handling events

    void PollEvents();

    // Mouse listeners
    void OnScroll(double xoffset, double yoffset);
    void OnDrag();

    // Window listeners
    void OnResize(int width, int height);

    // Misc listeners
    void OnDrop(int count, const char** paths);

    bool isScrolled;
    bool isDragged;
    bool isWindowResized;
    bool isFileDropped;

    // na razie wrzucę tutaj deklaracje struktur
    // jeśli uznamy, że trzymanie danych w ten sposób nam odpowiada, wrzuciłbym deklaracje do folderu `types`

    struct
    {
        double xOffset;
        double yOffset;
    } Scroll;

    // temp - do zweryfikowania po zaimplementowaniu
    struct
    {
        int startX; // ?
        int startY; // ?
    } Drag;

    struct
    {
        int count;
        std::string path;
    } DroppedFiles;

    struct
    {
        int newWidth;
        int newHeight;
    } Window;
};