#version 130

in vec4 vert_position;

out vec4 frag_position;

void main() {
	frag_position = (vert_position - vec4(0.25, 0, 0, 0));
	gl_Position = vert_position;
}