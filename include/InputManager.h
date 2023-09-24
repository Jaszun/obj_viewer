#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// na razie wrzucę tutaj deklaracje struktur

struct Scroll
{
    double xOffset;
    double yOffset;
};

struct Drag
{
    double xOffset;
    double yOffset;
};

struct DroppedFiles
{
    int count;
    std::string* paths;
};

struct Window
{
    int newWidth;
    int newHeight;
};

class InputManager
{
private:
    GLFWwindow* windowHandle;

    bool mRightMouseButtonPressed = false;
    bool mLeftMouseButtonPressed = false;
    
    void ResetEventBools();
public:
    bool isScrolled, isLeftDragged, isRightDragged, isWindowResized, isFileDropped;

    Scroll scroll;
    Drag dragStartPoint, dragCurrentPoint;
    DroppedFiles droppedFiles;
    Window window;

    InputManager(GLFWwindow* windowHandle);
    ~InputManager();

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
};