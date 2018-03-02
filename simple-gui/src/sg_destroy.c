/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 04:40:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:43:22 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_sg.h"

static void					sg_destroy_component(void *data)
{
	t_component				*component;

	component = (t_component *)data;
	free(component->data.data);
	if (component->data.vbo_count)
	{
		glDeleteBuffers(component->data.vbo_count, component->data.vbos);
		free(component->data.vbos);
	}
	free(component);
}

void						sg_destroy_scene(void *scene)
{
	t_llist					**queue;

	queue = &(((t_scene *)scene)->queue);
	ft_llist_del(queue, &sg_destroy_component);
	free(scene);
}

void						sg_remove_component(void *component)
{
	t_llist					**queue;

	queue = &(((t_scene *)((t_component *)component)->scene)->queue);
	ft_llist_rem(queue, (t_llist *)component, &sg_destroy_component);
}
