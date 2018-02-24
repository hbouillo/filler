/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:10:34 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/23 20:01:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

void			init_draw(GLuint vao, t_component_data *data, t_rect bounds)
{
	float		points[8];

	if (!data->vbos)
		data->vbos = (GLuint *)ft_memalloc(sizeof(GLuint) * 1);
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
	glGenTextures(1, &(((t_display *)data->data)->tex));
}

static void		uniforms(t_component_data *data, t_rect bounds)
{
	GLint		uniform;
	t_display	*display;
	float		fx;
	float		fy;

	display = (t_display *)data->data;
	fx = (float)(*(display->win_w)) / 2.0;
	fy = (float)(*(display->win_h)) / 2.0;
	uniform = glGetUniformLocation(data->shader_prog, "bounds");
	glUniform4i(uniform, (int)((bounds.x + 1.0) * fx),
		(int)((bounds.y + 1.0) * fy),
		(int)(bounds.w * fx),
		(int)(bounds.h * fy));
	uniform = glGetUniformLocation(data->shader_prog, "xcolor");
	sg_uniform_color(uniform, display->xcolor);
	uniform = glGetUniformLocation(data->shader_prog, "ocolor");
	sg_uniform_color(uniform, display->ocolor);
	uniform = glGetUniformLocation(data->shader_prog, "ecolor");
	sg_uniform_color(uniform, display->ecolor);
	uniform = glGetUniformLocation(data->shader_prog, "gcolor");
	sg_uniform_color(uniform, display->gcolor);
	uniform = glGetUniformLocation(data->shader_prog, "map");
	glUniform1i(uniform, 1);
	uniform = glGetUniformLocation(data->shader_prog, "edge");
	glUniform1i(uniform, display->edge);
	uniform = glGetUniformLocation(data->shader_prog, "mapSize");
	glUniform2i(uniform, (*(display->frame))->map->width, (*(display->frame))->map->height);
}

static void		compute_texture(t_display *display)
{
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->tex);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, (*(display->frame))->map->width, (*(display->frame))->map->height, 0, GL_RED_INTEGER, GL_UNSIGNED_BYTE, (*(display->frame))->map->map);
	display->last_frame = *(display->frame);
}

void			display_draw(void *component, t_component_data *data, t_rect bounds)
{
	t_pos		text_pos;
	t_display	*display;

	display = ((t_display *)data->data);
	glUseProgram(data->shader_prog);
	if (data->full_draw)
		init_draw(data->vao, data, bounds);
	if (!*(display->frame))
		return ;
	if (display->last_frame != *(display->frame) || data->full_draw)
		compute_texture(display);
	uniforms(data, bounds);
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->tex);
	glBindVertexArray(data->vao);
	glUniform1i(glGetUniformLocation(data->shader_prog, "render_mode"), 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glUniform1i(glGetUniformLocation(data->shader_prog, "render_mode"), 1);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
	data->full_draw = 0;
}
