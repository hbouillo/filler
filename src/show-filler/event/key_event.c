/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:05:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/22 06:21:43 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		handle_command_key_event(t_show *show, SDL_KeyboardEvent event)
{
	if (event.keysym.sym == SDLK_RIGHT)
	{
		if (show->frames && show->frames->next)
			show->frames = show->frames->next;
		show->gui.pause = 1;
	}
	else if (event.keysym.sym == SDLK_LEFT)
	{
		if (show->frames && show->frames->prev)
			show->frames = show->frames->prev;
		show->gui.pause = 1;
	}
	else if (event.keysym.sym == SDLK_SPACE)
		show->gui.pause = show->gui.pause ? 0 : 1;
	else if (event.keysym.sym == SDLK_DELETE ||
		event.keysym.sym == SDLK_BACKSPACE)
	{
		while (show->frames && show->frames->prev)
			show->frames = show->frames->prev;
	}
	else if (event.keysym.sym == SDLK_END)
	{
		while (show->frames && show->frames->next)
			show->frames = show->frames->next;
	}
}

void			handle_key_event(t_show *show, SDL_KeyboardEvent event)
{
	handle_command_key_event(show, event);
	if (event.keysym.sym == SDLK_RETURN)
	{
		if (SDL_GetWindowFlags(show->window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
			SDL_SetWindowFullscreen(show->window, 0);
		else
			SDL_SetWindowFullscreen(show->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}

}
