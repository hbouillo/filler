/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:46:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 05:12:11 by hbouillo         ###   ########.fr       */
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
	return (0);
}

static void			run(t_show *show)
{
	while (show->run)
	{
		run_event(show);
		run_logic(show);
		run_gui(show);
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
}

int					main(void)
{
	t_show			show;

	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error(ERR_SDL, ERR_CRITICAL);
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
	run(&show);
	SDL_GL_DeleteContext(show.context);
	SDL_DestroyWindow(show.window);
	SDL_Quit();
	return (0);
}
