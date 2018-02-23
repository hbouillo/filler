#version 410

#define ANTI_ALIASING 1
#define FLOOR_SQUARE_SIZE 1

#define VARIATION 0.4

#define x_char 120
#define X_char 88
#define o_char 111
#define O_char 79

uniform ivec4		bounds;

uniform vec4		xcolor;
uniform vec4		ocolor;
uniform vec4		ecolor;
uniform vec4		gcolor;

uniform int			edge;

uniform usampler2D	map;
uniform ivec2		mapSize;

out vec4 			frag_color;

float rand(vec2 co)
{
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

float		getSquareSize()
{
	float	size;

	size = float(bounds.z - 5 * 2) / float(mapSize.x);
	size = min(size, float(bounds.w - 5 * 2) / float(mapSize.y));
	return (FLOOR_SQUARE_SIZE == 1 ? floor(size) : size);
}

ivec2		getMapCoord(vec2 pos, vec4 newBounds)
{
	ivec2	mapCoord;

	mapCoord.x = int(floor(((pos.x - newBounds.x) / newBounds.z) * float(mapSize.x)));
	mapCoord.y = mapSize.y - 1 - int(floor(((pos.y - newBounds.y) / newBounds.w) * float(mapSize.y)));
	return (mapCoord);
}

bool		drawBorders(ivec2 mapCoord, vec4 newBounds)
{
	ivec2	under;
	ivec2	pos;

	pos = ivec2(int(floor(gl_FragCoord.x)), int(floor(gl_FragCoord.y)));
	under = getMapCoord(vec2(gl_FragCoord.x - 1.0, gl_FragCoord.y - 1.0), newBounds);

	if (pos.x <= int(floor(newBounds.x) - edge) ||
		pos.y <= int(floor(newBounds.y) - edge) ||
		pos.x >= int(floor(newBounds.x + newBounds.z) + edge) ||
		pos.y >= int(floor(newBounds.y + newBounds.w) + edge))
		discard ;
	if ((pos.x <= int(floor(newBounds.x))) ||
		(pos.y <= int(floor(newBounds.y))) ||
		(pos.x >= int(floor(newBounds.x + newBounds.z))) ||
		(pos.y >= int(floor(newBounds.y + newBounds.w))))
	{
		frag_color = ecolor;
		return (true);
	}
	if (under.x != mapCoord.x || under.y != mapCoord.y)
	{
		frag_color = gcolor;
		return (true);
	}

	return (false);
}

vec4		getNewBounds()
{
	vec4	newBounds;
	float	squareSize;

	squareSize = getSquareSize();
	newBounds.z = squareSize * float(mapSize.x);
	newBounds.w = squareSize * float(mapSize.y);
	newBounds.x = floor(float(bounds.x) + (float(bounds.z) - newBounds.z) / 2.0);
	newBounds.y = floor(float(bounds.y) + (float(bounds.w) - newBounds.w) / 2.0);
	return (newBounds);
}

void		main()
{
	ivec2	mapCoord;
	vec2	mapCoordF;
	uint	mapContent;
	vec4	newBounds;

	newBounds = getNewBounds();
	mapCoord = getMapCoord(gl_FragCoord.xy, newBounds);
	mapCoordF = vec2(float(mapCoord.x), float(mapCoord.y));
	if (drawBorders(mapCoord, newBounds))
		return ;
	mapContent = texelFetch(map, mapCoord, 0).r;
	if (mapContent == X_char)
		frag_color = vec4(xcolor.r * (1.0 - rand(mapCoordF) * VARIATION), xcolor.g * (1.0 - rand(mapCoordF) * VARIATION), xcolor.b * (1.0 - rand(mapCoordF) * VARIATION), xcolor.a);
	else if (mapContent == x_char)
		frag_color = vec4(xcolor.r + 0.1, xcolor.g + 0.1, xcolor.b + 0.1, xcolor.a);
	else if (mapContent == O_char)
		frag_color = vec4(ocolor.r * (1.0 - rand(mapCoordF) * VARIATION), ocolor.g * (1.0 - rand(mapCoordF) * VARIATION), ocolor.b * (1.0 - rand(mapCoordF) * VARIATION), ocolor.a);
	else if (mapContent == o_char)
		frag_color = vec4(ocolor.r + 0.1, ocolor.g + 0.1, ocolor.b + 0.1, ocolor.a);
	else
		discard ;
}
