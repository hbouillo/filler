/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:58:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 03:06:33 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./end_scene.h"

static void				heckyeah_action(void *component, t_component_data *data)
{
	component = NULL;
	data = NULL;
	push_user_event(FILLER_EVENT_SCENE, (void *)FILLER_SCENE_MAIN, NULL);
}

void					end_buttons(t_show *show, t_end_scene *end)
{
	if (!(end->heckyeah = sg_create_button(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->heckyeah,
		sg_recti(show->win_w / 2, show->win_h / 2 + END_SCENE_BUTTON_PADDING,
			END_SCENE_HECKYEAH_BUTTON_WIDTH, END_SCENE_BUTTON_HEIGHT));
	sg_set_flags(end->heckyeah, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_button_text(end->heckyeah, sg_new_gstr("Oh yeah",
		get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(end->heckyeah, END_SCENE_EDGE);
	sg_set_button_radius(end->heckyeah, END_SCENE_CORNER_RADIUS);
	sg_set_button_action(end->heckyeah, &heckyeah_action);
}

void					end_labels(t_show *show, t_end_scene *end)
{
	if (!(end->msg = sg_create_label(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->msg,
		sg_recti(show->win_w / 2, show->win_h / 2 + END_SCENE_LABEL_PADDING,
			0, 0));
	sg_set_flags(end->msg, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_label_text(end->msg, sg_new_gstr("Insert win sentence here",
		get_resource_path(FILLER_FONT), 1.3 * FILLER_TOP_FONT_SIZE));
	if (!(end->vs = sg_create_label(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->vs,
		sg_recti(show->win_w / 2,
			show->win_h / 2 + END_SCENE_SCORE_PADDING_Y - 7, 0, 0));
	sg_set_flags(end->vs, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_label_text(end->vs, sg_new_gstr("-",
		get_resource_path(FILLER_FONT), 2 * FILLER_TOP_FONT_SIZE));
}

void					end_labels_2(t_show *show, t_end_scene *end)
{
	if (!(end->score_1 = sg_create_label(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->score_1,
		sg_recti(show->win_w / 2 - END_SCENE_SCORE_PADDING_X,
			show->win_h / 2 + END_SCENE_SCORE_PADDING_Y, 0, 0));
	sg_set_flags(end->score_1, SG_LOCK_SIZE | SG_ALIGN_LEFT | SG_LOCK_MID);
	sg_set_label_text(end->score_1, sg_new_gstr("0",
		get_resource_path(FILLER_FONT), 2 * FILLER_TOP_FONT_SIZE));
	if (!(end->score_2 = sg_create_label(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->score_2,
		sg_recti(show->win_w / 2 + END_SCENE_SCORE_PADDING_X,
			show->win_h / 2 + END_SCENE_SCORE_PADDING_Y, 0, 0));
	sg_set_flags(end->score_2, SG_LOCK_SIZE | SG_ALIGN_RIGHT | SG_LOCK_MID);
	sg_set_label_text(end->score_2, sg_new_gstr("0",
		get_resource_path(FILLER_FONT), 2 * FILLER_TOP_FONT_SIZE));
}
