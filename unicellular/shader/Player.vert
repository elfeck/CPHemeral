#version 130

in vec4 vert_position;

uniform vec2 scale;
uniform vec3 camera;

void main() {
	gl_Position = vec4(vert_position.xy * scale + camera.xy, vert_position.zw);
}