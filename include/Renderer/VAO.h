#pragma once

#include "Renderer/VBO.h"
#include "shared/Vertex.h"

class VAO
{
private:
    unsigned int VAOid{};

public:
    VAO();
    ~VAO();

    void Bind() const;
    void Unbind() const;

    void AddBuffer(const VBO &vertexBuffer);
};
