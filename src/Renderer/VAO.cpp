#include "Renderer/VAO.h"

VAO::VAO()
{
    glCreateVertexArrays(1, &VAOid);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &VAOid);
}

void VAO::Bind() const
{
    glBindVertexArray(VAOid);
}

void VAO::Unbind() const
{
    glBindVertexArray(0);
}

void VAO::AddBuffer(const VBO &vbo)
{
    glVertexArrayVertexBuffer(VAOid, 0, vbo.getID(), 0, sizeof(Vertex));

    glEnableVertexArrayAttrib(VAOid, 0);
    glEnableVertexArrayAttrib(VAOid, 1);
    glEnableVertexArrayAttrib(VAOid, 2);

    glVertexArrayAttribFormat(VAOid, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
    glVertexArrayAttribFormat(VAOid, 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, normal));
    glVertexArrayAttribFormat(VAOid, 2, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, uv));

    glVertexArrayAttribBinding(VAOid, 0, 0);
    glVertexArrayAttribBinding(VAOid, 1, 0);
    glVertexArrayAttribBinding(VAOid, 2, 0);
}
