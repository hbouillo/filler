/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:05:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/21 05:13:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void			handle_key_event(t_show *show, SDL_KeyboardEvent event)
{
	if (event.keysym.sym == SDLK_RIGHT)
		if (show->frames && show->frames->next)
			show->frames = show->frames->next;
	if (event.keysym.sym == SDLK_LEFT)
		if (show->frames && show->frames->prev)
			show->frames = show->frames->prev;
}
