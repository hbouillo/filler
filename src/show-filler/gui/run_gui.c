/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_gui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:58:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:27:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gui.h"

static void				run_gui(t_show *show)
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
		pthread_mutex_lock(&(show->mutex));
		if (show->gui.active_scene != NULL)
			sg_draw(show->gui.active_scene->ptr);
		pthread_mutex_unlock(&(show->mutex));
		last_time = current_time;
		SDL_GL_SwapWindow(show->window);
	}
}

static void				*run_thread(void *arg)
{
	t_show				*show;

	pthread_detach(pthread_self());
	pthread_setname_np("Gui");
	show = (t_show *)arg;
	show->context = SDL_GL_CreateContext(show->window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(show->gui.colors->background.r, show->gui.colors->background.g,
		show->gui.colors->background.b, show->gui.colors->background.a);
	while (1)
		run_gui(show);
}

void					start_gui(t_show *show)
{
	pthread_t			gui_thread;

	pthread_create(&gui_thread, NULL, &run_thread, show);
}
