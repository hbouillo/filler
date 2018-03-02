/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:39:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:38:57 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rectangle.h"

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
	t_rectangle	*rectangle;
	float		fx;
	float		fy;

	fx = (float)(sg_get_shared_data()->window_w) / 2.0;
	fy = (float)(sg_get_shared_data()->window_h) / 2.0;
	rectangle = (t_rectangle *)data->data;
	uniform = glGetUniformLocation(data->shader_prog, "clipBounds");
	glUniform4i(uniform, (int)((bounds.x + 1.0) * fx),
		(int)((bounds.y + 1.0) * fy),
		(int)(bounds.w * fx),
		(int)(bounds.h * fy));
	uniform = glGetUniformLocation(data->shader_prog, "icolor");
	sg_uniform_color(uniform, rectangle->icolor);
	uniform = glGetUniformLocation(data->shader_prog, "ocolor");
	sg_uniform_color(uniform, rectangle->ocolor);
	uniform = glGetUniformLocation(data->shader_prog, "radius");
	glUniform1i(uniform, rectangle->radius);
	uniform = glGetUniformLocation(data->shader_prog, "edge");
	glUniform1i(uniform, rectangle->edge);
}

void			rectangle_draw(void *component, t_component_data *data,
					t_rect bounds)
{
	t_rectangle	*rectangle;

	component = NULL;
	rectangle = ((t_rectangle *)data->data);
	glUseProgram(data->shader_prog);
	if (data->full_draw)
	{
		if ((data->full_draw = init_draw(data->vao, data, bounds)))
			return ;
	}
	uniforms(data, bounds);
	glBindVertexArray(data->vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}
