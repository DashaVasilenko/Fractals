//#version 330

uniform mat4 View;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec3 color;
out mat4 viewMatrix;

void main() {
    viewMatrix = View;
    gl_Position = vec4(position, 1.0f);
}