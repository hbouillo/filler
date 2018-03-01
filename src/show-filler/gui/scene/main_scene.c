/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 22:20:24 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

static void				buttons(t_show *show, t_main_scene *main)
{
	pause_button(show, main);
	next_button(show, main);
	prev_button(show, main);
	end_button(show, main);
	begin_button(show, main);
}

static void				update_button_color(t_show *show, void *button)
{
	sg_set_button_icolor(button, show->gui.colors->background);
	sg_set_button_ocolor(button, show->gui.colors->main_text);
	sg_set_button_hcolor(button, show->gui.colors->button_hover);
	sg_set_button_pcolor(button, show->gui.colors->button_pressed);
	sg_set_button_text_color(button, show->gui.colors->main_text);
}

void					main_update_colors(t_show *show, t_main_scene *main)
{
	sg_set_rectangle_icolor(main->top_frame, show->gui.colors->background);
	sg_set_rectangle_ocolor(main->top_frame, show->gui.colors->main_text);
	sg_set_label_color(main->p1_label, show->gui.colors->display_o);
	sg_set_label_color(main->p2_label, show->gui.colors->display_x);
	sg_set_label_color(main->vs_label, show->gui.colors->main_text);
	sg_set_label_color(main->p1_score_label, show->gui.colors->display_o);
	sg_set_label_color(main->p2_score_label, show->gui.colors->display_x);
	show_set_display_ocolor(main->display_frame, show->gui.colors->display_o);
	show_set_display_xcolor(main->display_frame, show->gui.colors->display_x);
	show_set_display_ecolor(main->display_frame,
		show->gui.colors->display_edge);
	show_set_display_gcolor(main->display_frame,
		show->gui.colors->display_grid);
	update_button_color(show, main->pause_button);
	update_button_color(show, main->next_button);
	update_button_color(show, main->prev_button);
	update_button_color(show, main->end_button);
	update_button_color(show, main->begin_button);
}

void					init_main_scene(t_show *show, t_main_scene *main)
{
	if (!(main->ptr = sg_new_scene(show->window)))
		error(ERR_MALLOC, ERR_CRITICAL);
	frames(show, main);
	labels_1(show, main);
	labels_2(show, main);
	score_labels(show, main);
	display(show, main);
	buttons(show, main);
	main_update_colors(show, main);
}
