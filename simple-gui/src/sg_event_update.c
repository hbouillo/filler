/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_event_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 05:14:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:16:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_sg.h"

void				update_mouse(int x, int y)
{
	t_shared		*shared;

	shared = sg_get_shared_data();
	shared->mouse_init = 1;
	shared->mouse_pos.x = (x / (float)shared->window_w) * 2.0 - 1.0;
	shared->mouse_pos.y = ((shared->window_h - y)
		/ (float)shared->window_h) * 2.0 - 1.0;
}

void				update_window(int width, int height)
{
	t_shared		*shared;

	shared = sg_get_shared_data();
	if (shared->window_w == width && shared->window_h == height)
		return ;
	shared->last_window_w = shared->window_w;
	shared->last_window_h = shared->window_h;
	shared->window_w = width;
	shared->window_h = height;
	glViewport(0, 0, shared->window_w, shared->window_h);
}
