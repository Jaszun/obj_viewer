#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
    static void resize_callback(GLFWwindow* window, int width, int height);
    static void drop_callback(GLFWwindow* window, int count, const char** paths);
};