/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:24:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 01:36:33 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

static void		push_frame(t_show *show, t_frame *frame)
{
	t_frame		*queue;

	queue = show->frames;
	if (!queue)
		show->frames = frame;
	else
	{
		frame->id++;
		while (queue->next)
		{
			queue = queue->next;
			frame->id++;
		}
		frame->prev = queue;
		queue->next = frame;
	}
}

void			handle_new_frame_event(t_show *show, SDL_UserEvent user_event)
{
	t_frame 	*new_frame;

	if (!(new_frame = (t_frame *)ft_memalloc(sizeof(t_frame))))
		error(ERR_MALLOC, ERR_CRITICAL);
	new_frame->map = (t_map *)user_event.data1;
	push_frame(show, new_frame);
	ft_putchar('.');
}
