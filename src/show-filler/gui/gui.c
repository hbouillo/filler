/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:21:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 04:37:10 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gui.h"

void					uninit_gui(t_show *show)
{
	sg_destroy_scene(show->gui.scenes[FILLER_SCENE_MAIN].ptr);
	sg_destroy_scene(show->gui.scenes[FILLER_SCENE_END].ptr);
}

void					init_gui(t_show *show)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	show->gui.pause = 0;
	set_color_set(show, 0);
	init_main_scene(show, &(show->gui.scenes[FILLER_SCENE_MAIN].main));
	init_end_scene(show, &(show->gui.scenes[FILLER_SCENE_END].end));
	show->gui.active_scene = show->gui.scenes + FILLER_SCENE_MAIN;
}

static void				draw_gui(t_show *show)
{
	if (show->gui.active_scene == show->gui.scenes + FILLER_SCENE_END)
	{
		sg_draw(show->gui.scenes[FILLER_SCENE_MAIN].ptr);
	}
	sg_draw(show->gui.active_scene->ptr);
}

void					run_gui(t_show *show)
{
	static t_time		last_time;
	t_time				current_time;
	unsigned long		delta;

	clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
	if (!last_time.tv_sec)
		last_time = current_time;
	delta = (current_time.tv_sec - last_time.tv_sec) * 1000000000 +
			current_time.tv_nsec - last_time.tv_nsec;
	if (delta > 1000000000 / FRAME_PER_SECOND)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (show->gui.active_scene != NULL)
		{
			draw_gui(show);
		}
		delta -= 1000000000 / FRAME_PER_SECOND;
		last_time = current_time;
		SDL_GL_SwapWindow(show->window);
	}
}
