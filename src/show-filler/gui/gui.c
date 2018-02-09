/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:21:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 05:06:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gui.h"

t_gui				*get_gui()
{
	static t_gui	gui;

	return (&gui);
}

void				init_gui(t_show *show)
{
	t_gui			*gui;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	gui = get_gui();
	init_main_scene(show->window, &(gui->scenes[FILLER_SCENE_MAIN].main));
	gui->active_scene = gui->scenes + FILLER_SCENE_MAIN;
}

void				run_gui(t_show *show)
{
	t_gui			*gui;

	gui = get_gui();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gui->active_scene != NULL)
		hgui_draw(gui->active_scene->ptr);
	SDL_GL_SwapWindow(show->window);
}

void				run_gui_event(SDL_Event e)
{
	int				index;
	t_gui			*gui;

	gui = get_gui();
	index = -1;
	while (++index)
	{
		if (gui->scenes + index == gui->active_scene)
			hgui_event(gui->scenes[index].ptr, e, HGUI_MODE_ACTIVE);
		else
			hgui_event(gui->scenes[index].ptr, e, HGUI_MODE_PASSIVE);
	}
}
