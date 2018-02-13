/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:21:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/13 05:19:43 by hbouillo         ###   ########.fr       */
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
	init_main_scene(show, &(gui->scenes[FILLER_SCENE_MAIN].main));
	gui->active_scene = gui->scenes + FILLER_SCENE_MAIN;
}

void				run_gui(t_show *show)
{
	static t_time		last_time;
	t_time				current_time;
	unsigned long		delta;
	t_gui			*gui;

	gui = get_gui();
	clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
	if (!last_time.tv_sec)
		last_time = current_time;
	delta = (current_time.tv_sec - last_time.tv_sec) * 1000000000 +
			current_time.tv_nsec - last_time.tv_nsec;
	int i = 0;
	if (delta > 1000000000 / FRAME_PER_SECOND)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (gui->active_scene != NULL)
			hgui_draw(gui->active_scene->ptr);
		delta -= 1000000000 / FRAME_PER_SECOND;
		last_time = current_time;
		SDL_GL_SwapWindow(show->window);
	}
}

void				run_gui_event(SDL_Event e)
{
	int				index;
	t_gui			*gui;

	gui = get_gui();
	index = -1;
	while (++index < FILLER_SCENES_AMOUNT)
	{
		if (gui->scenes + index == gui->active_scene)
			hgui_event(gui->scenes[index].ptr, e, HGUI_MODE_ACTIVE);
		else
			hgui_event(gui->scenes[index].ptr, e, HGUI_MODE_PASSIVE);
	}
}
