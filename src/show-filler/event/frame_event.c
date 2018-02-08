/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:24:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/08 01:47:00 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

void		handle_new_frame_event(t_show *show, SDL_UserEvent user_event)
{
	// t_frame *new_frame;
    //
	// if (!(new_frame = (t_frame *)ft_memalloc(sizeof(t_frame))))
	// 	error(ERR_MALLOC, ERR_CRITICAL);
	// frame->map = (t_map *)user_event.data1;
	ft_printf("New frame !\n");
}
