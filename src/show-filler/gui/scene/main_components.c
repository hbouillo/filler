/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:47:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:49:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

void					display(t_show *show, t_main_scene *main)
{
	if (!(main->display_frame = show_create_display(main->ptr, show)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->display_frame,
		sg_recti(2 * MAIN_SCENE_MARGIN,
				2 * MAIN_SCENE_MARGIN + MAIN_SCENE_BUTTON_HEIGHT,
				show->win_w - 4 * MAIN_SCENE_MARGIN,
				show->win_h - 4 * MAIN_SCENE_MARGIN -
							MAIN_SCENE_TOP_HEIGHT -
							MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->display_frame, SG_ALIGN_TOP | SG_ALIGN_RIGHT |
		SG_LOCK_BOTTOM | SG_LOCK_LEFT | SG_LOCK_TOP | SG_LOCK_RIGHT);
	show_set_display_edge(main->display_frame, MAIN_SCENE_EDGE + 1);
}

void					frames(t_show *show, t_main_scene *main)
{
	if (!(main->top_frame = sg_create_rectangle(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->top_frame,
		sg_recti(MAIN_SCENE_MARGIN, show->win_h - MAIN_SCENE_MARGIN,
			show->win_w - 2 * MAIN_SCENE_MARGIN, MAIN_SCENE_TOP_HEIGHT));
	sg_set_flags(main->top_frame, SG_ALIGN_RIGHT | SG_ALIGN_BOTTOM |
		SG_LOCK_TOP | SG_LOCK_LEFT | SG_LOCK_RIGHT | SG_LOCK_HEIGHT);
	sg_set_rectangle_radius(main->top_frame, MAIN_SCENE_CORNER_RADIUS);
	sg_set_rectangle_edge(main->top_frame, MAIN_SCENE_EDGE);
}

void					labels_1(t_show *show, t_main_scene *main)
{
	if (!(main->vs_label = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->vs_label,
		sg_recti(show->win_w / 2, show->win_h - MAIN_SCENE_MARGIN - 25, 0, 0));
	sg_set_flags(main->vs_label, SG_LOCK_TOP
		| SG_LOCK_SIZE);
	sg_set_label_text(main->vs_label, sg_new_gstr("vs",
		get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
}

void					labels_2(t_show *show, t_main_scene *main)
{
	if (!(main->p1_label = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->p1_label,
		sg_recti(2 * MAIN_SCENE_MARGIN, show->win_h - MAIN_SCENE_MARGIN - 25,
			0, 0));
	sg_set_flags(main->p1_label, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->p1_label, sg_new_gstr("Player 1",
		get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	if (!(main->p2_label = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->p2_label,
		sg_recti(show->win_w - 2 * MAIN_SCENE_MARGIN,
				show->win_h - MAIN_SCENE_MARGIN - 25, 0, 0));
	sg_set_flags(main->p2_label, SG_LOCK_TOP
		| SG_LOCK_RIGHT | SG_LOCK_SIZE
		| SG_ALIGN_LEFT);
	sg_set_label_text(main->p2_label, sg_new_gstr("Player 2",
		get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
}
