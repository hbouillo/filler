/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:28:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/28 22:33:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

unsigned int	get_user_event(void)
{
	static unsigned int	user_event = 0xFFFFFFFF;

	if (user_event == 0xFFFFFFFF)
		user_event = SDL_RegisterEvents(1);
	if (user_event == 0xFFFFFFFF)
		error(ERR_SDL, ERR_CRITICAL);
	return (user_event);
}

void			push_user_event(int code, void *data1, void *data2)
{
	SDL_Event	e;

	e.type = get_user_event();
	e.user.code = code;
	e.user.data1 = data1;
	e.user.data2 = data2;
	SDL_PushEvent(&e);
}

static void		handle_events(t_show *show, SDL_Event event)
{
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
			event.key.keysym.sym == SDLK_ESCAPE))
	{
		pthread_mutex_lock(&(show->run_mutex));
		show->run = 0;
		pthread_mutex_unlock(&(show->run_mutex));
	}
	if (event.type == SDL_KEYDOWN)
		handle_key_event(show, event.key);
	if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		show->win_w = (int)event.window.data1;
		show->win_h = (int)event.window.data2;
	}
	if (event.type == get_user_event())
	{
		if (event.user.code == FILLER_EVENT_FRAME)
			handle_new_frame_event(show, event.user);
		else if (event.user.code == FILLER_EVENT_PLAYERS)
			handle_players_event(show, event.user);
		else if (event.user.code == FILLER_EVENT_RESULT)
			handle_result_event(show, event.user);
	}
}

int				run_event(t_show *show)
{
	SDL_Event		event;
	int				index;

	while (SDL_PollEvent(&event))
	{
		handle_events(show, event);
		index = -1;
		while (++index < FILLER_SCENES_AMOUNT)
		{
			if (show->gui.scenes + index == show->gui.active_scene)
				sg_event(show->gui.scenes[index].ptr, event,
					SG_MODE_ACTIVE);
			else
				sg_event(show->gui.scenes[index].ptr, event,
					SG_MODE_PASSIVE);
		}
	}
	return (0);
}
