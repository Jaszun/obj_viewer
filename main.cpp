#include <iostream>
#include "App.h"

int main() {
    std::cout << "Hello world!" << std::endl;

    App app(800, 600, "obj viewer");
    app.Run();

    return 0;
}
