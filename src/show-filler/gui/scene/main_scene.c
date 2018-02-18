/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/18 19:10:32 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

static void				buttons(t_show *show, t_main_scene *main)
{
	main->top_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->top_button, sg_recti(20, show->win_h - 20, show->win_w - 2 * 20, 50));
	sg_set_flags(main->top_button, SG_ALIGN_RIGHT | SG_ALIGN_BOTTOM | SG_LOCK_TOP | SG_LOCK_LEFT | SG_LOCK_RIGHT
		| SG_LOCK_HEIGHT);
	sg_set_button_icolor(main->top_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_ocolor(main->top_button, sg_colorf(FILLER_COLOR_TEXT));
	sg_set_button_hcolor(main->top_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_pcolor(main->top_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_radius(main->top_button, 10);
	sg_set_button_edge(main->top_button, 1);
	main->mid_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->mid_button, sg_recti(20, 20, show->win_w - 2 * 20, show->win_h - 20 - 20 - 50 - 20));
	sg_set_flags(main->mid_button, SG_ALIGN_TOP | SG_ALIGN_RIGHT | SG_LOCK_BOTTOM | SG_LOCK_LEFT | SG_LOCK_TOP | SG_LOCK_RIGHT);
	sg_set_button_icolor(main->mid_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_ocolor(main->mid_button, sg_colorf(FILLER_COLOR_TEXT));
	sg_set_button_hcolor(main->mid_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_pcolor(main->mid_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_radius(main->mid_button, 10);
	sg_set_button_edge(main->mid_button, 1);
}

static void				labels(t_show *show, t_main_scene *main)
{
	static char const	*font = FILLER_FONT;

	main->p1_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->p1_label, sg_recti(40, show->win_h - 20 - 25, 0, 0));
	sg_set_flags(main->p1_label, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->p1_label, sg_new_gstr("Player 1", get_resource_path(font), FILLER_TOP_FONT_SIZE));
	sg_set_label_color(main->p1_label, sg_colorf(FILLER_COLOR_TEXT));
	main->p2_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->p2_label, sg_recti(show->win_w - 40, show->win_h - 20 - 25, 0, 0));
	sg_set_flags(main->p2_label, SG_LOCK_TOP
		| SG_LOCK_RIGHT | SG_LOCK_SIZE
		| SG_ALIGN_LEFT);
	sg_set_label_text(main->p2_label, sg_new_gstr("Player 2", get_resource_path(font), 20));
	sg_set_label_color(main->p2_label, sg_colorf(FILLER_COLOR_TEXT));
	main->vs_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->vs_label, sg_recti(show->win_w / 2, show->win_h - 20 - 25, 0, 0));
	sg_set_flags(main->vs_label, SG_LOCK_TOP
		| SG_LOCK_SIZE);
	sg_set_label_text(main->vs_label, sg_new_gstr("vs", get_resource_path(font), FILLER_TOP_FONT_SIZE));
	sg_set_label_color(main->vs_label, sg_colorf(FILLER_COLOR_TEXT));
}

void					init_main_scene(t_show *show, t_main_scene *main)
{

	main->ptr = sg_new_scene(show->window);
	buttons(show, main);
	labels(show, main);
}
