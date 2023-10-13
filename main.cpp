#include <iostream>
#include "App.h"

#include <GLFW/glfw3.h>

int main()
{
    // std::cout << "Hello world!" << std::endl;

    App app(800, 600, "obj viewer");
    app.Run();
    // glfwTerminate();
    return 0;
}
