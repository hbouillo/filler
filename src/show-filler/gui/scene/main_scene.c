/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 05:28:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gui.h"

void				init_main_scene(SDL_Window *window, t_main_scene *main)
{
	t_label			label;
	t_rect			bounds;

	main->ptr = hgui_new_scene(window);
	label.label = "";
	label.font = hgui_create_font(main->ptr, "Simple_tfb.ttf", 100, hgui_colori(255, 255, 255, 255));
	bounds = hgui_rectf(0.0, 0.5, 0.4, 0.2);
	hgui_set_flags(main->ptr, hgui_create_label(main->ptr, bounds, label), 0);
}
