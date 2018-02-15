/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/15 20:06:22 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

static void				buttons(t_show *show, t_main_scene *main)
{
	t_button	button;
	t_rect		bounds;

	button.icolor = hgui_colorf(FILLER_COLOR_BACKGROUND);
	button.ocolor = hgui_colorf(FILLER_COLOR_TEXT);
	button.hcolor = button.icolor;
	button.pcolor = button.icolor;
	button.button_action = NULL;
	button.radius = 10;
	button.edge = 3;
	button.gstr = NULL;
	bounds = hgui_rectf(0.0, 0.85, 1.9, 0.15);
	main->top_button = hgui_create_button(main->ptr, bounds, button);
	hgui_set_flags(main->ptr, main->top_button, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_HEIGHT);
	bounds = hgui_rectf(0.0, 0.70, 1.9, 1.6);
	main->mid_button = hgui_create_button(main->ptr, bounds, button);
	hgui_set_flags(main->ptr, main->mid_button, HGUI_ALIGN_BOTTOM);
}

static void				labels(t_show *show, t_main_scene *main)
{
	static char const	*font = "fonts/good_times_rg.ttf";
	t_label				label;
	t_rect				bounds;

	label.gstr = hgui_new_gstr("Player 1", get_resource_path(font), 25);
	label.color = hgui_colorf(FILLER_COLOR_TEXT);
	bounds = hgui_rectf(-0.9, 0.85, 0.0, 0.0);
	main->p1_label = hgui_create_label(main->ptr, bounds, label);
	hgui_set_flags(main->ptr, main->p1_label, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_LEFT | STATE_COMPONENT_LOCK_SIZE
		| HGUI_ALIGN_RIGHT);
	label.gstr = hgui_new_gstr("Player 2", get_resource_path(font), 25);
	bounds = hgui_rectf(0.9, 0.85, 0.0, 0.0);
	main->p2_label = hgui_create_label(main->ptr, bounds, label);
	hgui_set_flags(main->ptr, main->p2_label, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_RIGHT | STATE_COMPONENT_LOCK_SIZE
		| HGUI_ALIGN_LEFT);
	label.gstr = hgui_new_gstr("vs", get_resource_path(font), 25);
	bounds = hgui_rectf(0.0, 0.85, 0.0, 0.0);
	main->vs_label = hgui_create_label(main->ptr, bounds, label);
	hgui_set_flags(main->ptr, main->vs_label, STATE_COMPONENT_LOCK_TOP
		| STATE_COMPONENT_LOCK_SIZE);
}

void					init_main_scene(t_show *show, t_main_scene *main)
{

	main->ptr = hgui_new_scene(show->window);
	buttons(show, main);
	labels(show, main);
}
