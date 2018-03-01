/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:28:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 22:18:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"
#include <unistd.h>

static void		update_scores(t_show *show)
{
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_MAIN].main.p1_score_label,
		sg_new_gstr(ft_itoa(show->frames->score.score_1),
			get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_MAIN].main.p2_score_label,
		sg_new_gstr(ft_itoa(show->frames->score.score_2),
			get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
}

static void			play_frames(t_show *show)
{
	static t_time		last_time;
	t_time				current_time;
	unsigned long		delta;

	clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
	if (!last_time.tv_sec)
		last_time = current_time;
	delta = (current_time.tv_sec - last_time.tv_sec) * 1000000000 +
			current_time.tv_nsec - last_time.tv_nsec;
	if (delta > 1000000000L / (unsigned long)show->tps)
	{
		if (!show->gui.pause)
		{
			if (show->frames)
				if (show->frames->next)
					show->frames = show->frames->next;
			update_scores(show);
		}
		last_time = current_time;
	}
}

int					run_logic(t_show *show)
{
	play_frames(show);
	return (0);
}
