/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:39:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:38:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./button.h"

static int		init_draw(GLuint vao, t_component_data *data, t_rect bounds)
{
	float		points[8];

	data->vbo_count = 1;
	if (!data->vbos)
	{
		if (!(data->vbos = (GLuint *)ft_memalloc(sizeof(GLuint) * 1)))
			return (1);
	}
	else
		glDeleteBuffers(1, data->vbos);
	sg_rect_to_vec2buf(bounds, points);
	glGenBuffers(1, data->vbos);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, data->vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), points, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (0);
}

static void		uniforms(t_component_data *data, t_rect bounds)
{
	GLint		uniform;
	t_button	*button;
	t_pos		f;

	f.x = (float)(sg_get_shared_data()->window_w) / 2.0;
	f.y = (float)(sg_get_shared_data()->window_h) / 2.0;
	button = (t_button *)data->data;
	uniform = glGetUniformLocation(data->shader_prog, "clipBounds");
	glUniform4i(uniform, (int)((bounds.x + 1.0) * f.x),
		(int)((bounds.y + 1.0) * f.y),
		(int)(bounds.w * f.x),
		(int)(bounds.h * f.y));
	uniform = glGetUniformLocation(data->shader_prog, "icolor");
	if (data->states & SG_PRESSED)
		sg_uniform_color(uniform, button->pcolor);
	else if (data->states & SG_HOVERED)
		sg_uniform_color(uniform, button->hcolor);
	else
		sg_uniform_color(uniform, button->icolor);
	uniform = glGetUniformLocation(data->shader_prog, "ocolor");
	sg_uniform_color(uniform, button->ocolor);
	uniform = glGetUniformLocation(data->shader_prog, "radius");
	glUniform1i(uniform, button->radius);
	uniform = glGetUniformLocation(data->shader_prog, "edge");
	glUniform1i(uniform, button->edge);
}

void			button_draw(void *component, t_component_data *data,
					t_rect bounds)
{
	t_pos		text_pos;
	t_button	*button;

	component = NULL;
	button = ((t_button *)data->data);
	glUseProgram(data->shader_prog);
	if (data->full_draw)
	{
		if ((data->full_draw = init_draw(data->vao, data, bounds)))
			return ;
		sg_resize_gstr(button->gstr);
	}
	uniforms(data, bounds);
	glBindVertexArray(data->vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
	if (button->gstr)
	{
		text_pos.y = bounds.y + bounds.h / 2
			- sg_get_gstr(button->gstr)->size.h / 2;
		text_pos.x = bounds.x + bounds.w / 2
			- sg_get_gstr(button->gstr)->size.w / 2;
		sg_draw_gstr(button->gstr, button->font_color, text_pos);
	}
}
