/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:18:49 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:25:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gui.h"

static t_color_set		set_from_tab(int *color_set)
{
	t_color_set			set;

	set.background = sg_color(color_set[0]);
	set.main_text = sg_color(color_set[1]);
	set.display_edge = sg_color(color_set[2]);
	set.display_grid = sg_color(color_set[3]);
	set.display_o = sg_color(color_set[4]);
	set.display_x = sg_color(color_set[5]);
	set.button_hover = sg_color(color_set[6]);
	set.button_pressed = sg_color(color_set[7]);
	return (set);
}

static t_color_set		*get_color_set(int set)
{
	static int			init;
	static t_color_set	sets[10];

	if (!init)
	{
		sets[init++] = set_from_tab((int[8]) { 0x252525, 0xe2e2e2, 0xe2e2e2,
			0xaf252525, 0xf2f2f2, 0x7f7f7f, 0x3a3a3a, 0x606060 });
		sets[init++] = set_from_tab((int[8]) { 0xe2e2e2, 0x565656, 0x565656,
			0xafe2e2e2, 0x474747, 0x999999, 0xcecece, 0xbcbcbc });
		sets[init++] = set_from_tab((int[8]) { 0xe2e2e2, 0x565656, 0x565656,
			0xafe2e2e2, 0xa14fff, 0xff4949, 0xc593ff, 0xff8787 });
	}
	if (set >= init)
		set = 0;
	return (&(sets[set]));
}

void					set_color_set(t_show *show, int set)
{
	show->gui.colors = get_color_set(set);
	if (show->gui.scenes[FILLER_SCENE_MAIN].ptr)
		main_update_colors(show, &(show->gui.scenes[FILLER_SCENE_MAIN].main));
	glClearColor(show->gui.colors->background.r, show->gui.colors->background.g,
		show->gui.colors->background.b, show->gui.colors->background.a);
}