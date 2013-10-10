#version 130

in vec4 vert_color;
in vec4 vert_position;

uniform vec4 color;

out vec3 frag_color;

void main() {
	gl_Position = vert_position;
	frag_color = vec3(vert_color.x, vert_color.y, vert_color.z);
}