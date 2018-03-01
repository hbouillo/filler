/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:46:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:45:57 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"
#include <unistd.h>

static int			init_show(t_show *show)
{
	ft_bzero(show, sizeof(t_show));
	show->run = 1;
	show->tps = TICKS_PER_SECOND;
	pthread_mutex_init(&(show->run_mutex), NULL);
	return (0);
}

static void			run(t_show *show)
{
	pthread_t		read_thread;

	read_thread = start_read(show);
	while (show->run)
	{
		run_event(show);
		run_logic(show);
		run_gui(show);
	}
	pthread_join(read_thread, NULL);
}

void				init_sdl_window(t_show *show)
{
	if (!(show->window = SDL_CreateWindow("Filler",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		show->max_size.w * 2 / 3,
		show->max_size.h * 2 / 3,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)))
		error(ERR_SDL, ERR_CRITICAL);
	show->context = SDL_GL_CreateContext(show->window);
	show->win_w = show->max_size.w * 2 / 3;
	show->win_h = show->max_size.h * 2 / 3;
	SDL_SetWindowMinimumSize(show->window, 1000, 670);
}

static void			free_show_content(t_show *show)
{
	t_frame			*tmp;

	free(show->players[0]);
	free(show->players[1]);
	if (show->frames)
	{
		while (show->frames->prev)
			show->frames = show->frames->prev;
		while (show->frames->next)
		{
			tmp = show->frames;
			show->frames = show->frames->next;
			free(tmp->map->map);
			free(tmp->map);
			free(tmp);
		}
		free(show->frames->map->map);
		free(show->frames->map);
		free(show->frames);
	}
}

int					main(void)
{
	t_show			show;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error(ERR_SDL, ERR_CRITICAL);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	if (init_show(&show))
		error(ERR_SDL, ERR_CRITICAL);
	if (SDL_GetDisplayUsableBounds(0, &show.max_size) < 0)
	{
		error(ERR_SDL, ERR_WARNING);
		show.max_size.w = 1280 * 3 / 2;
		show.max_size.h = 720 * 3 / 2;
	}
	init_sdl_window(&show);
	init_gui(&show);
	run(&show);
	uninit_gui(&show);
	sg_del_all_gstr();
	free_show_content(&show);
	SDL_GL_DeleteContext(show.context);
	SDL_DestroyWindow(show.window);
	SDL_Quit();
	return (0);
}
