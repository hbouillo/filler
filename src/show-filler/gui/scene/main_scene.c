/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 18:08:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

static void				buttons(t_show *show, t_main_scene *main)
{
	main->top_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->top_button, sg_rectf(0.0, 0.85, 1.9, 0.15));
	sg_set_flags(main->top_button, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_HEIGHT);
	sg_set_button_icolor(main->top_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_ocolor(main->top_button, sg_colorf(FILLER_COLOR_TEXT));
	sg_set_button_hcolor(main->top_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_pcolor(main->top_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_radius(main->top_button, 10);
	sg_set_button_edge(main->top_button, 3);
	main->mid_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->mid_button, sg_rectf(0.0, 0.70, 1.9, 1.6));
	sg_set_flags(main->mid_button, SG_ALIGN_BOTTOM);
	sg_set_button_icolor(main->mid_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_ocolor(main->mid_button, sg_colorf(FILLER_COLOR_TEXT));
	sg_set_button_hcolor(main->mid_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_pcolor(main->mid_button, sg_colorf(FILLER_COLOR_BACKGROUND));
	sg_set_button_radius(main->mid_button, 10);
	sg_set_button_edge(main->mid_button, 3);
}

static void				labels(t_show *show, t_main_scene *main)
{
	static char const	*font = "fonts/good_times_rg.ttf";

	main->p1_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->p1_label, sg_rectf(-0.9, 0.85, 0.0, 0.0));
	sg_set_flags(main->p1_label, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_LEFT | STATE_COMPONENT_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->p1_label, sg_new_gstr("Player 1", get_resource_path(font), 25));
	sg_set_label_color(main->p1_label, sg_colorf(FILLER_COLOR_TEXT));
	main->p2_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->p2_label, sg_rectf(0.9, 0.85, 0.0, 0.0));
	sg_set_flags(main->p2_label, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_RIGHT | STATE_COMPONENT_LOCK_SIZE
		| SG_ALIGN_LEFT);
	sg_set_label_text(main->p2_label, sg_new_gstr("Player 2", get_resource_path(font), 25));
	sg_set_label_color(main->p2_label, sg_colorf(FILLER_COLOR_TEXT));
	main->vs_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->vs_label, sg_rectf(0.0, 0.85, 0.0, 0.0));
	sg_set_flags(main->vs_label, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_SIZE);
	sg_set_label_text(main->vs_label, sg_new_gstr("vs", get_resource_path(font), 25));
	sg_set_label_color(main->vs_label, sg_colorf(FILLER_COLOR_TEXT));
}

void					init_main_scene(t_show *show, t_main_scene *main)
{

	main->ptr = sg_new_scene(show->window);
	buttons(show, main);
	labels(show, main);
}
