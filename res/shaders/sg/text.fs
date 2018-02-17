#version 410

uniform sampler2D	tex;
uniform vec4		text_color;

in vec2				uv;

out vec4			frag_color;

void				main()
{
	frag_color = vec4(1.0, 1.0, 1.0, texture(tex, uv).r) * text_color;
}
