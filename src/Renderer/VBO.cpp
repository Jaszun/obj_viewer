#include "Renderer/VBO.h"

VBO::VBO()
{
}

VBO::VBO(const void *data, unsigned int size)
{
    glCreateBuffers(1, &VBOid);
    glNamedBufferStorage(VBOid, sizeof(Vertex) * size, data, GL_DYNAMIC_STORAGE_BIT);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &VBOid);
}

void VBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
}

void VBO::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const unsigned int VBO::getID() const
{
    return VBOid;
}
