/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:08:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:27:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

static t_display	*default_display_data(t_show *show)
{
	t_display		*display_data;

	if (!(display_data = (t_display *)ft_memalloc(sizeof(t_display))))
		error(ERR_MALLOC, ERR_CRITICAL);
	display_data->xcolor = sg_colorf(0.0, 0.0, 0.0, 0.0);
	display_data->ocolor = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->frame = &(show->frames);
	display_data->win_h = &(show->win_h);
	display_data->win_w = &(show->win_w);
	display_data->tex = 0;
	display_data->last_frame = NULL;
	return (display_data);
}

void				*show_create_display(void *scene, t_show *show)
{
	void			*display_ptr;
	char			*fs;
	char			*vs;
	GLuint			shader;

	if (!(fs = get_resource_path("shaders/display.fs")) ||
		!(vs = get_resource_path("shaders/display.vs")))
		return (NULL);
	shader = get_shader_prog(fs, vs);
	if (shader == 0)
		return (NULL);
	if (!(display_ptr = sg_create_component(scene, shader)))
		return (NULL);
	free(fs);
	free(vs);
	sg_set_component_draw(display_ptr, &display_draw);
	sg_set_component_event(display_ptr, &display_event);
	sg_set_component_data(display_ptr, default_display_data(show));
	return (display_ptr);
}
