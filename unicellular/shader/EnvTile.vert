#version 130

in vec4 vert_position;

uniform vec3 camera;
uniform mat4 mvp_matrix;

void main() {
	gl_Position = mvp_matrix * vec4(vert_position.xy + camera.xy, vert_position.zw);
}