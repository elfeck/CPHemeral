#version 130

in vec3 frag_color;

uniform vec4 color;

void main() {
    gl_FragColor = vec4(frag_color.x, frag_color.y, frag_color.z, color.w);
}