#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

uniform vec3 u_Color = vec3(1.0, 0.0, 1.0);

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vertColor;

void main(void)
{
    vertColor = u_Color;
    gl_Position = projection * view * model * vec4(position, 1.0);
}
