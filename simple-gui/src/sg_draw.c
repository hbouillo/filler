/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 01:16:42 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 16:52:04 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_sg.h"

void				sg_draw(void *scene)
{
	t_llist			*queue;
	t_component		*component;
	t_rect			bounds;

	queue = ((t_scene *)scene)->queue;
	while (queue)
	{
		component = (t_component *)queue->data;
		bounds = component->bounds;
		sg_align_bounds(&bounds, component->data.states);
		if (!component->hide && component->draw)
			component->draw(component, &(component->data), bounds);
		queue = queue->next;
	}
}
