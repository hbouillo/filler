/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:19:42 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 21:25:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./font.h"

static t_font_renderer		*get_font_renderer(void)
{
	static t_font_renderer	font_renderer;
	char					*fs;
	char					*vs;

	if (!font_renderer.init)
	{
		font_renderer.init = 1;
		glGenVertexArrays(1, &(font_renderer.vao));
		glActiveTexture(GL_TEXTURE0);
		glGenTextures(1, &(font_renderer.tex));
		if (!(fs = get_resource_path("shaders/sg/text.fs")) ||
			!(vs = get_resource_path("shaders/sg/text.vs")))
			return (&font_renderer);
		font_renderer.shader = get_shader_prog(fs, vs);
		free(fs);
		free(vs);
	}
	return (&font_renderer);
}

static void					draw_glyph(float x, float y, t_glyph g)
{
	static float const		uv[8] = { 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0 };
	float					box[8];
	GLuint					vbos[2];

	sg_rect_to_vec2buf(sg_rect(sg_posf_pad(x, y), sg_sizei(g.width, g.rows)),
						box);
	glGenBuffers(2, vbos);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), box, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), uv, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindTexture(GL_TEXTURE_2D, get_font_renderer()->tex);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, g.width, g.rows, 0, GL_RED,
		GL_UNSIGNED_BYTE, g.buffer);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDeleteBuffers(2, vbos);
}

void						sg_draw_gstr(void *gstr_ptr, t_color color,
								t_pos pos)
{
	t_glyph					*glyphs;
	t_pos					f;
	t_pos					d;

	if (get_font_renderer()->shader == 0)
		return ;
	glyphs = sg_get_gstr(gstr_ptr)->glyphs;
	f.x = 2.0 / (float)sg_get_shared_data()->window_w;
	f.y = 2.0 / (float)sg_get_shared_data()->window_h;
	glUseProgram(get_font_renderer()->shader);
	glBindVertexArray(get_font_renderer()->vao);
	glUniform1i(glGetUniformLocation(get_font_renderer()->shader, "tex"), 0);
	sg_uniform_color(glGetUniformLocation(get_font_renderer()->shader,
		"text_color"), color);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	while (glyphs->buffer)
	{
		d.x = (float)(glyphs->hori_bearing_x) * f.x / 64.0;
		d.y = (float)(glyphs->height - glyphs->hori_bearing_y) * f.y / 64.0;
		draw_glyph(pos.x + d.x, pos.y - d.y, *(glyphs));
		pos.x += (float)(glyphs->advance_x) * f.x / 64.0;
		pos.y += (float)(glyphs->advance_y) * f.y / 64.0;
		glyphs++;
	}
}
