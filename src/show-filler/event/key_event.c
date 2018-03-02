/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:05:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 03:05:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		set_pause(t_show *show, int pause)
{
	if (pause)
	{
		show->gui.pause = 1;
		sg_set_button_text(
			show->gui.scenes[FILLER_SCENE_MAIN].main.pause_button,
			sg_new_gstr("Play",
				get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	}
	else
	{
		show->gui.pause = 0;
		sg_set_button_text(
			show->gui.scenes[FILLER_SCENE_MAIN].main.pause_button,
			sg_new_gstr("Pause",
				get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	}
}

static void		handle_command_key_event(t_show *show, SDL_KeyboardEvent event)
{
	if (event.keysym.sym == SDLK_RIGHT)
	{
		if (show->frames && show->frames->next)
			show->frames = show->frames->next;
		set_pause(show, 1);
	}
	else if (event.keysym.sym == SDLK_LEFT)
	{
		if (show->frames && show->frames->prev)
			show->frames = show->frames->prev;
		set_pause(show, 1);
	}
	else if (event.keysym.sym == SDLK_SPACE)
		set_pause(show, show->gui.pause ? 0 : 1);
	else if (event.keysym.sym == SDLK_DELETE ||
		event.keysym.sym == SDLK_BACKSPACE)
		while (show->frames && show->frames->prev)
			show->frames = show->frames->prev;
	else if (event.keysym.sym == SDLK_END)
		while (show->frames && show->frames->next)
			show->frames = show->frames->next;
	else
		return ;
	frame_update(show);
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

static void		handle_escape(t_show *show)
{
	SDL_Event	e;

	if (show->gui.active_scene == show->gui.scenes + FILLER_SCENE_MAIN)
	{
		e.type = SDL_QUIT;
		SDL_PushEvent(&e);
	}
	else if (show->gui.active_scene == show->gui.scenes + FILLER_SCENE_END)
		push_user_event(FILLER_EVENT_SCENE, (void *)FILLER_SCENE_MAIN, NULL);
}

void			handle_key_event(t_show *show, SDL_KeyboardEvent event)
{
	if (event.type == SDL_KEYDOWN && event.keysym.sym == SDLK_ESCAPE)
		handle_escape(show);
	if (show->gui.active_scene == show->gui.scenes + FILLER_SCENE_MAIN)
		handle_command_key_event(show, event);
	handle_color_set_pick(show, event);
	if (event.keysym.sym == SDLK_RETURN)
	{
		if (SDL_GetWindowFlags(show->window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
			SDL_SetWindowFullscreen(show->window, 0);
		else
			SDL_SetWindowFullscreen(show->window,
				SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
}
