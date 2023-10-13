#pragma once

#include <iostream>

#include <glad/glad.h>

#include "Renderer/Vertex.h"

class VBO
{
private:
    unsigned int VBOid;

public:
    VBO();
    VBO(const void *data, unsigned int size);
    ~VBO();

    void Bind() const;
    void Unbind() const;

    const unsigned int getID() const;
};
