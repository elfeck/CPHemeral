#version 130

in vec3 frag_color;

uniform vec4 color;

void main() {
    gl_FragColor = vec4(1 - frag_color.x, frag_color.y, 1 - frag_color.z, color.w);
}