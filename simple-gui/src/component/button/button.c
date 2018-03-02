/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:06:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:20:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./button.h"
#include "sg_commands.h"

static t_button	*default_button_data(void)
{
	t_button	*button_data;

	if (!(button_data = (t_button *)ft_memalloc(sizeof(t_button))))
		return (NULL);
	button_data->font_color = sg_colorf(1.0, 1.0, 1.0, 1.0);
	button_data->icolor = sg_colorf(0.0, 0.0, 0.0, 0.0);
	button_data->ocolor = sg_colorf(1.0, 1.0, 1.0, 1.0);
	button_data->hcolor = sg_colorf(0.2, 0.2, 0.2, 1.0);
	button_data->pcolor = sg_colorf(0.5, 0.5, 0.5, 1.0);
	button_data->radius = 0;
	button_data->edge = 1;
	return (button_data);
}

void			*sg_create_button(void *scene)
{
	void		*button_ptr;
	char		*fs;
	char		*vs;
	GLuint		shader;

	if (!(fs = get_resource_path("shaders/sg/button.fs")) ||
		!(vs = get_resource_path("shaders/sg/button.vs")))
		return (NULL);
	shader = get_shader_prog(fs, vs);
	if (shader == 0 ||
		!(button_ptr = sg_create_component(scene, shader)))
		return (NULL);
	free(vs);
	free(fs);
	sg_set_component_draw(button_ptr, &button_draw);
	sg_set_component_event(button_ptr, &button_event);
	if (!(((t_component *)button_ptr)->data.data = default_button_data()))
		return (NULL);
	return (button_ptr);
}
