/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:46:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/27 21:10:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

void			error(int errcode, char const *const errmsg, char *errtype,
					int errexit)
{
	printf("%s (ERRCODE=%d, ERRMSG=\"%s\")\n", errtype, errcode, errmsg);
	if (errexit)
	{
		SDL_Quit();
		exit(1);
	}
}

static int			init_show(t_show *show)
{
	ft_bzero(show, sizeof(t_show));
	show->run = 1;
	show->tps = TICKS_PER_SECOND;
	return (0);
}

static void			run(t_show *show)
{
	t_time			before_time;
	t_time			after_time;
	unsigned long	delta;

	while (show->run)
	{
		run_event(show);
		run_logic(show);
		clock_gettime(CLOCK_MONOTONIC_RAW, &before_time);
		run_gui(show);
		clock_gettime(CLOCK_MONOTONIC_RAW, &after_time);
		delta = (after_time.tv_sec - before_time.tv_sec) * 1000000000 +
				after_time.tv_nsec - before_time.tv_nsec;
		// if (delta / 1000 > 100)
		// 	printf("Frame time: %f, ms\n", ((float)(delta / 1000)) / 1000);
	}
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

int					main(void)
{
	t_show			show;

	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error(ERR_SDL, ERR_CRITICAL);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
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
	glClearColor(show.gui.colors->background.r, show.gui.colors->background.g,
		show.gui.colors->background.b, show.gui.colors->background.a);
	run(&show);
	SDL_GL_DeleteContext(show.context);
	SDL_DestroyWindow(show.window);
	SDL_Quit();
	return (0);
}
