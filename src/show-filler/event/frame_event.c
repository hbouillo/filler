/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:24:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 00:44:07 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void			update_scores(t_show *show)
{
	char			*tmp;

	if (!show->frames)
		return ;
	tmp = ft_itoa(show->frames->score.score_1);
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_MAIN].main.p1_score_label,
		sg_new_gstr(tmp,
			get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	free(tmp);
	tmp = ft_itoa(show->frames->score.score_2);
	sg_set_label_text(
		show->gui.scenes[FILLER_SCENE_MAIN].main.p2_score_label,
		sg_new_gstr(tmp,
			get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	free(tmp);
}

void				frame_update(t_show *show)
{
	update_scores(show);
	if (show->end && !show->frames->next)
		push_user_event(FILLER_EVENT_SCENE, (void *)FILLER_SCENE_END, NULL);
}

static void			push_frame(t_show *show, t_frame *frame)
{
	t_frame			*queue;

	queue = show->frames;
	if (!queue)
		show->frames = frame;
	else
	{
		frame->id++;
		while (queue->next)
		{
			queue = queue->next;
			frame->id++;
		}
		frame->prev = queue;
		queue->next = frame;
	}
}

void				handle_new_frame_event(t_show *show,
						SDL_UserEvent user_event)
{
	static t_result	score;
	t_frame			*new;
	int				index;

	if (!(new = (t_frame *)ft_memalloc(sizeof(t_frame))))
		error(ERR_MALLOC, ERR_CRITICAL);
	new->map = (t_map *)user_event.data1;
	index = -1;
	while (++index < new->map->height * new->map->width)
	{
		if (new->map->map[index] == 'x' || new->map->map[index] == 'o')
		{
			new->map->map[index] == 'o' ? score.score_1++ : score.score_2++;
			break ;
		}
	}
	new->score = score;
	push_frame(show, new);
}
