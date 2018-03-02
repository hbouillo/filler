/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:45:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 02:46:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./component.h"

void				*sg_create_component(void *scene, GLuint shader_prog)
{
	t_component		*component;

	if (!(component = (t_component *)ft_memalloc(sizeof(t_component))))
		return (NULL);
	component->scene = scene;
	component->data.shader_prog = shader_prog;
	glGenVertexArrays(1, &(component->data.vao));
	sg_queue_component(component);
	return (component);
}
