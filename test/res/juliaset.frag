#version 130

in vec2 frag_position;

uniform vec2 c;

float julia_iterative(in vec2 point, in vec2 constant, in float threshold, in int depth) {
	int i = 0;
	for(i = 0; i < depth && dot(point, point) < threshold * threshold; i++) {
		vec2 next = vec2(point.x * point.x - point.y * point.y, 2 * point.x * point.y);
		point = next + constant;
	}
	return i;
}

void main() {
	int depth = 1000;
	float threshold = 4.0;
	vec2 constant = (c.x == 0 && c.y == 0) ? frag_position : c;

	float green = julia_iterative(frag_position, constant, threshold, depth) / depth;
	gl_FragColor = vec4(green / 1.4, green, 0, 1.0);
}