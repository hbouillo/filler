/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:28:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/13 03:29:51 by hbouillo         ###   ########.fr       */
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

int				run_event(t_show *show)
{
	SDL_Event		event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
				event.key.keysym.sym == SDLK_ESCAPE))
			show->run = 0;
		if (event.type == get_user_event())
		{
			if (event.user.code == FILLER_EVENT_FRAME)
				handle_new_frame_event(show, event.user);
			else if (event.user.code == FILLER_EVENT_PLAYERS)
				handle_players_event(show, event.user);
			else if (event.user.code == FILLER_EVENT_RESULT)
				handle_result_event(show, event.user);
		}
		run_gui_event(event);
	}
	return (0);
}
