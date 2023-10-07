#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

uniform vec3 u_Color = vec3(1.0, 0.0, 1.0);

out vec3 vertColor;

void main(void)
{
    vertColor = u_Color;
    gl_Position = vec4(position, 1.0);
}
