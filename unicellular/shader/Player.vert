#version 130

in vec4 vert_position;

uniform vec2 scale;
uniform vec2 offset;
uniform vec3 camera;

uniform mat4 mvp_matrix;


void main() {
	gl_Position = mvp_matrix * vec4(vert_position.xy * scale + offset + camera.xy, vert_position.zw);
}