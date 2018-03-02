/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 01:03:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 03:05:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		update_end_gui(t_show *show, t_result score)
{
	char		*end_label;

	if (score.score_1 == score.score_2)
		end_label = ft_strdup("It's a draw !");
	else
		end_label = ft_strjoin(
			show->players[score.score_1 > score.score_2 ? 0 : 1], " wins !");
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_END].end.score_1,
		sg_new_gstr(ft_itoa(score.score_1),
			get_resource_path(FILLER_FONT), 2 * FILLER_TOP_FONT_SIZE));
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_END].end.score_2,
		sg_new_gstr(ft_itoa(score.score_2),
			get_resource_path(FILLER_FONT), 2 * FILLER_TOP_FONT_SIZE));
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_END].end.msg,
		sg_new_gstr(end_label,
			get_resource_path(FILLER_FONT), 1.3 * FILLER_TOP_FONT_SIZE));
	free(end_label);
}

void			handle_result_event(t_show *show, SDL_UserEvent user_event)
{
	t_frame		*frame;

	user_event.data1 = NULL;
	frame = show->frames;
	while (frame->next)
		frame = frame->next;
	show->end = 1;
	update_end_gui(show, frame->score);
}
