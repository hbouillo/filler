#version 410

#define ANTI_ALIASING 1

uniform ivec4	clipBounds;
uniform vec4	icolor;
uniform vec4	ocolor;
uniform int		radius;
uniform int		edge;

out vec4 frag_color;

void		clip()
{
	if (int(gl_FragCoord.x) <= clipBounds.x || int(gl_FragCoord.x) >= clipBounds.x + clipBounds.z)
		discard;
	if (int(gl_FragCoord.y) <= clipBounds.y || int(gl_FragCoord.y) >= clipBounds.y + clipBounds.w)
		discard;
}

float		circleIntensity(ivec2 pos, ivec2 center, int radius)
{
	float	intensity = 1.0;
	float 	dist = sqrt(pow(float(center.x - pos.x), 2.0) + pow(float(center.y - pos.y), 2.0));

	if (dist > float(radius))
		intensity = max (1.0 - (dist - float(radius)), 0);
	return (intensity);
}

vec4		circle_with_edge(ivec2 center, int radius, int edge, vec4 ocolor, vec4 icolor)
{
	ivec2	pos = ivec2(gl_FragCoord.x, gl_FragCoord.y);
	float	circle_intensity;
	float	edge_intensity;
	vec4	color;

	radius--;

	if (edge > 0)
		edge++;
	circle_intensity = circleIntensity(pos, center, radius - edge);
	edge_intensity = circleIntensity(pos, center, radius);
	color = ocolor;
	if (circle_intensity == 0)
		color.w *= edge_intensity;
	else
		color = (edge_intensity - circle_intensity) * ocolor + circle_intensity * icolor;
	return (color);
}

void		main()
{
	clip();

	if (int(gl_FragCoord.x) < clipBounds.x + radius && int(gl_FragCoord.y) < clipBounds.y + radius)
		frag_color = circle_with_edge(ivec2(clipBounds.x + radius, clipBounds.y + radius), radius, edge, ocolor, icolor);
	else if (int(gl_FragCoord.x) < clipBounds.x + radius && int(gl_FragCoord.y) > clipBounds.y + clipBounds.w - radius)
		frag_color = circle_with_edge(ivec2(clipBounds.x + radius, clipBounds.y + clipBounds.w - radius), radius, edge, ocolor, icolor);
	else if (int(gl_FragCoord.x) > clipBounds.x + clipBounds.z - radius && int(gl_FragCoord.y) < clipBounds.y + radius)
		frag_color = circle_with_edge(ivec2(clipBounds.x + clipBounds.z - radius, clipBounds.y + radius), radius, edge, ocolor, icolor);
	else if (int(gl_FragCoord.x) > clipBounds.x + clipBounds.z - radius && int(gl_FragCoord.y) > clipBounds.y + clipBounds.w - radius)
		frag_color = circle_with_edge(ivec2(clipBounds.x + clipBounds.z - radius, clipBounds.y + clipBounds.w - radius), radius, edge, ocolor, icolor);
	else if (edge != 0 && (
			(int(gl_FragCoord.x) < clipBounds.x + edge + 2 && int(gl_FragCoord.x) > clipBounds.x) ||
			(int(gl_FragCoord.y) < clipBounds.y + edge + 2 && int(gl_FragCoord.y) > clipBounds.y) ||
			(int(gl_FragCoord.x) > clipBounds.x + clipBounds.z - edge - 2 && int(gl_FragCoord.x) < clipBounds.x + clipBounds.z) ||
			(int(gl_FragCoord.y) > clipBounds.y + clipBounds.w - edge - 2 && int(gl_FragCoord.y) < clipBounds.y + clipBounds.w)))
		frag_color = ocolor;
	else
		frag_color = icolor;
}
