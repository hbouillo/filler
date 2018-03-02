/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:50:28 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:40:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_sg.h"

t_shared					*sg_get_shared_data(void)
{
	static t_shared			shared;

	return (&shared);
}

void						*sg_new_scene(SDL_Window *window)
{
	t_shared				*shared;
	t_scene					*scene;

	shared = sg_get_shared_data();
	if (!shared->init)
	{
		shared->init = 1;
		SDL_GetWindowSize(window, &(shared->window_w), &(shared->window_h));
		shared->last_window_w = shared->window_w;
		shared->last_window_h = shared->window_h;
	}
	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
		return (NULL);
	return (scene);
}

void						*sg_queue_component(t_component *component)
{
	t_llist					*new_queue;
	t_llist					**queue;

	new_queue = ft_llist_new(component);
	queue = &(((t_scene *)((t_component *)component)->scene)->queue);
	ft_llist_back(queue, new_queue);
	return (new_queue);
}
