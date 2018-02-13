/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/13 05:26:49 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gui.h"

void				init_main_scene(t_show *show, t_main_scene *main)
{
	t_label			label;
	t_rect			bounds;

	main->ptr = hgui_new_scene(show->window);
	label.gstr = hgui_create_glyph_string(main->ptr,
		get_resource_path("fonts/PoiretOne-Regular.ttf"),
		50,
		"Player 1");
	label.color = hgui_colori(255, 255, 255, 255);
	bounds = hgui_rectf(-0.95, 0.9, 0.0, 0.0);
	main->p1_label = hgui_create_label(main->ptr, bounds, label);
	hgui_set_flags(main->ptr, main->p1_label, STATE_COMPONENT_LOCK_TOP | STATE_COMPONENT_LOCK_LEFT | HGUI_ALIGN_RIGHT);
	label.gstr = hgui_create_glyph_string(main->ptr,
		get_resource_path("fonts/PoiretOne-Regular.ttf"),
		50,
		"Player 2");
	bounds = hgui_rectf(0.95, 0.9, 0.0, 0.0);
	main->p2_label = hgui_create_label(main->ptr, bounds, label);
	hgui_set_flags(main->ptr, main->p2_label, STATE_COMPONENT_LOCK_TOP | STATE_COMPONENT_LOCK_RIGHT | HGUI_ALIGN_LEFT);
	label.gstr = hgui_create_glyph_string(main->ptr,
		get_resource_path("fonts/PoiretOne-Regular.ttf"),
		50,
		"vs");
	bounds = hgui_rectf(0.0, 0.89, 0.0, 0.0);
	main->vs_label = hgui_create_label(main->ptr, bounds, label);
	hgui_set_flags(main->ptr, main->vs_label, STATE_COMPONENT_LOCK_TOP);
}
