/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:37:26 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/14 05:08:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

static void			update_gui_p1(t_show *show)
{
	t_main_scene	*main;

	main = &(show->gui.scenes[FILLER_SCENE_MAIN].main);
	hgui_set_label_text(main->ptr, main->p1_label, hgui_new_gstr(
		show->players[0],
		get_resource_path("fonts/good_times_rg.ttf"),
		35));
}

static void			update_gui_p2(t_show *show)
{
	t_main_scene	*main;

	main = &(show->gui.scenes[FILLER_SCENE_MAIN].main);
	hgui_set_label_text(main->ptr, main->p2_label, hgui_new_gstr(
		show->players[1],
		get_resource_path("fonts/good_times_rg.ttf"),
		35));
}

void				handle_players_event(t_show *show, SDL_UserEvent user_event)
{
	if (!show->players[0] && user_event.data1)
	{
		show->players[0] = (char *)user_event.data1;
		update_gui_p1(show);
	}
	if (!show->players[1] && user_event.data2)
	{
		show->players[1] = (char *)user_event.data2;
		update_gui_p2(show);
	}
}
