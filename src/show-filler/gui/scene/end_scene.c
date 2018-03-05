/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:04:53 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/05 05:51:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./end_scene.h"

static void				background(t_end_scene *end)
{
	if (!(end->background = sg_create_rectangle(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->background,
		sg_rectf(-1.1, -1.1, 2.2, 2.2));
	sg_set_flags(end->background, SG_ALIGN_RIGHT | SG_ALIGN_TOP);
	sg_set_rectangle_edge(end->background, 0);
	sg_set_rectangle_radius(end->background, 0);
}

static void				popup(t_show *show, t_end_scene *end)
{
	if (!(end->popup = sg_create_rectangle(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->popup,
		sg_recti(show->win_w / 2, show->win_h / 2,
			END_SCENE_POPUP_WIDTH, END_SCENE_POPUP_HEIGHT));
	sg_set_flags(end->popup, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_rectangle_radius(end->popup, END_SCENE_CORNER_RADIUS);
	sg_set_rectangle_edge(end->popup, END_SCENE_EDGE);
}

void					end_update_colors(t_show *show, t_end_scene *end)
{
	t_color				background;

	background = show->gui.colors->background;
	background.a = 0.8;
	sg_set_button_icolor(end->heckyeah, show->gui.colors->background);
	sg_set_button_ocolor(end->heckyeah, show->gui.colors->main_text);
	sg_set_button_hcolor(end->heckyeah, show->gui.colors->button_hover);
	sg_set_button_pcolor(end->heckyeah, show->gui.colors->button_pressed);
	sg_set_button_text_color(end->heckyeah, show->gui.colors->main_text);
	sg_set_rectangle_icolor(end->popup, show->gui.colors->background);
	sg_set_rectangle_ocolor(end->popup, show->gui.colors->main_text);
	sg_set_rectangle_icolor(end->background, background);
	sg_set_rectangle_ocolor(end->background, show->gui.colors->main_text);
	sg_set_label_color(end->msg, show->gui.colors->main_text);
	sg_set_label_color(end->vs, show->gui.colors->main_text);
	sg_set_label_color(end->score_1, show->gui.colors->display_o);
	sg_set_label_color(end->score_2, show->gui.colors->display_x);
}

void					init_end_scene(t_show *show, t_end_scene *end)
{
	if (!(end->ptr = sg_new_scene(show->window)))
		error(ERR_MALLOC, ERR_CRITICAL);
	background(end);
	popup(show, end);
	end_labels(show, end);
	end_labels_2(show, end);
	end_buttons(show, end);
	end_update_colors(show, end);
}
