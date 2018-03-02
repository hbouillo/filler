/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:06:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:20:20 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rectangle.h"
#include "sg_commands.h"

static t_rectangle	*default_rectangle_data(void)
{
	t_rectangle		*rectangle_data;

	if (!(rectangle_data = (t_rectangle *)ft_memalloc(sizeof(t_rectangle))))
		return (NULL);
	rectangle_data->icolor = sg_colorf(0.0, 0.0, 0.0, 0.0);
	rectangle_data->ocolor = sg_colorf(1.0, 1.0, 1.0, 1.0);
	rectangle_data->radius = 0;
	rectangle_data->edge = 1;
	return (rectangle_data);
}

void				*sg_create_rectangle(void *scene)
{
	void			*rectangle_ptr;
	char			*fs;
	char			*vs;
	GLuint			shader;

	if (!(fs = get_resource_path("shaders/sg/button.fs")) ||
		!(vs = get_resource_path("shaders/sg/button.vs")))
		return (NULL);
	shader = get_shader_prog(fs, vs);
	if (shader == 0 ||
		!(rectangle_ptr = sg_create_component(scene, shader)))
		return (NULL);
	free(vs);
	free(fs);
	sg_set_component_draw(rectangle_ptr, &rectangle_draw);
	sg_set_component_event(rectangle_ptr, &rectangle_event);
	if (!(((t_component *)rectangle_ptr)->data.data = default_rectangle_data()))
		return (NULL);
	return (rectangle_ptr);
}
