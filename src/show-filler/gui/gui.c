/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:21:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/22 06:02:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./show_filler.h"

void				init_gui(t_show *show)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	init_main_scene(show, &(show->gui.scenes[FILLER_SCENE_MAIN].main));
	show->gui.active_scene = show->gui.scenes + FILLER_SCENE_MAIN;
	show->gui.pause = 0;
}

void				run_gui(t_show *show)
{
	static t_time		last_time;
	t_time				current_time;
	unsigned long		delta;

	clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
	if (!last_time.tv_sec)
		last_time = current_time;
	delta = (current_time.tv_sec - last_time.tv_sec) * 1000000000 +
			current_time.tv_nsec - last_time.tv_nsec;
	int i = 0;
	if (delta > 1000000000 / FRAME_PER_SECOND)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (show->gui.active_scene != NULL)
			sg_draw(show->gui.active_scene->ptr);
		delta -= 1000000000 / FRAME_PER_SECOND;
		last_time = current_time;
		SDL_GL_SwapWindow(show->window);
	}
}
