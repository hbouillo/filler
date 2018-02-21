#version 410

#define ANTI_ALIASING 1

#define x_char 120
#define X_char 88
#define o_char 111
#define O_char 79
#define FILLER_COLOR 0.3, 0.3, 0.3, 1.0

uniform ivec4		bounds;
uniform vec4		xcolor;
uniform vec4		ocolor;
uniform usampler2D	map;
uniform ivec2		mapSize;

out vec4 			frag_color;

void		main()
{
	ivec2	mapCoord;
	uint	mapContent;

	mapCoord.x = int(((gl_FragCoord.x - float(bounds.x)) / float(bounds.z)) * float(mapSize.x));
	mapCoord.y = mapSize.y - 1 - int(((gl_FragCoord.y - float(bounds.y)) / float(bounds.w)) * float(mapSize.y));
	mapContent = texelFetch(map, mapCoord, 0).r;
	if (mapContent == x_char || mapContent == X_char)
		frag_color = vec4(FILLER_COLOR);
	else if (mapContent == o_char || mapContent == O_char)
		frag_color = vec4(0.7, 0.7, 0.7, 1.0);
	else
		discard ;
}
