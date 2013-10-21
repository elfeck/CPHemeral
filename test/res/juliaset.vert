#version 130

in vec4 vert_position;

uniform float zoom;
uniform vec2 camera;

out vec2 frag_position;

void main() {
	frag_position = vec2(vert_position) * zoom + camera;
	gl_Position = vert_position;
}