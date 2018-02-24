/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:05:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/23 23:40:15 by hbouillo         ###   ########.fr       */
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

static void		handle_color_set_pick(t_show *show, SDL_KeyboardEvent event)
{
	if (event.keysym.sym == SDLK_0)
		set_color_set(show, 9);
	else if (event.keysym.sym == SDLK_1)
		set_color_set(show, 0);
	else if (event.keysym.sym == SDLK_2)
		set_color_set(show, 1);
	else if (event.keysym.sym == SDLK_3)
		set_color_set(show, 2);
	else if (event.keysym.sym == SDLK_4)
		set_color_set(show, 3);
	else if (event.keysym.sym == SDLK_5)
		set_color_set(show, 4);
	else if (event.keysym.sym == SDLK_6)
		set_color_set(show, 5);
	else if (event.keysym.sym == SDLK_7)
		set_color_set(show, 6);
	else if (event.keysym.sym == SDLK_8)
		set_color_set(show, 7);
	else if (event.keysym.sym == SDLK_9)
		set_color_set(show, 8);
}

void			handle_key_event(t_show *show, SDL_KeyboardEvent event)
{
	handle_command_key_event(show, event);
	handle_color_set_pick(show, event);
	if (event.keysym.sym == SDLK_RETURN)
	{
		if (SDL_GetWindowFlags(show->window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
			SDL_SetWindowFullscreen(show->window, 0);
		else
			SDL_SetWindowFullscreen(show->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
}
