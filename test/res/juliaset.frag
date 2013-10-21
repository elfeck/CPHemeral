#version 130

in vec4 frag_position;

uniform vec2 c;
uniform float zoom;

int julia_iterative(in vec2 point, in float threshold, in int depth) {
	int i = 0;
	for(i = 0; i < depth && sqrt(dot(point, point)) < threshold; i++) {
		vec2 squared = vec2(pow(point.x, 2) - pow(point.y, 2), 2.0f * point.x * point.y);
		point += squared + c;
	}
	return i;
}

void main() {
	int depth = 500;

	float blue = julia_iterative(vec2(frag_position) * zoom, 4.0, depth) / depth;
	gl_FragColor = vec4(0.0, 0.0, blue, 1.0);
}