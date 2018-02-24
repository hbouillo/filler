/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:23:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/23 23:49:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gui.h"

static void				display(t_show *show, t_main_scene *main)
{
	main->display_frame = show_create_display(main->ptr, show);
	sg_set_component_boundaries(main->display_frame,
		sg_recti(MAIN_SCENE_MARGIN * 2,
				MAIN_SCENE_MARGIN * 2 + MAIN_SCENE_BOTTOM_HEIGHT,
				show->win_w - 2 * MAIN_SCENE_MARGIN * 2,
				show->win_h - MAIN_SCENE_MARGIN * 4 -
							MAIN_SCENE_TOP_HEIGHT -
							MAIN_SCENE_BOTTOM_HEIGHT));
	sg_set_flags(main->display_frame, SG_ALIGN_TOP | SG_ALIGN_RIGHT | SG_LOCK_BOTTOM | SG_LOCK_LEFT | SG_LOCK_TOP | SG_LOCK_RIGHT);
	show_set_display_edge(main->display_frame, MAIN_SCENE_EDGE + 1);
}

static void				frames(t_show *show, t_main_scene *main)
{
	main->top_frame = sg_create_rectangle(main->ptr);
	sg_set_component_boundaries(main->top_frame,
		sg_recti(MAIN_SCENE_MARGIN, show->win_h - MAIN_SCENE_MARGIN,
			show->win_w - 2 * MAIN_SCENE_MARGIN, MAIN_SCENE_TOP_HEIGHT));
	sg_set_flags(main->top_frame, SG_ALIGN_RIGHT | SG_ALIGN_BOTTOM | SG_LOCK_TOP | SG_LOCK_LEFT | SG_LOCK_RIGHT
		| SG_LOCK_HEIGHT);
	sg_set_rectangle_radius(main->top_frame, MAIN_SCENE_CORNER_RADIUS);
	sg_set_rectangle_edge(main->top_frame, MAIN_SCENE_EDGE);
	main->bottom_frame = sg_create_rectangle(main->ptr);
	sg_set_component_boundaries(main->bottom_frame,
		sg_recti(MAIN_SCENE_MARGIN, MAIN_SCENE_MARGIN,
			show->win_w - 2 * MAIN_SCENE_MARGIN, MAIN_SCENE_BOTTOM_HEIGHT));
	sg_set_flags(main->bottom_frame, SG_ALIGN_RIGHT | SG_ALIGN_TOP | SG_LOCK_BOTTOM | SG_LOCK_LEFT | SG_LOCK_RIGHT
		| SG_LOCK_HEIGHT);
	sg_set_rectangle_radius(main->bottom_frame, MAIN_SCENE_CORNER_RADIUS);
	sg_set_rectangle_edge(main->bottom_frame, MAIN_SCENE_EDGE);
}

static void				labels(t_show *show, t_main_scene *main)
{
	main->p1_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->p1_label,
		sg_recti(MAIN_SCENE_MARGIN * 2, show->win_h - MAIN_SCENE_MARGIN - 25,
			0, 0));
	sg_set_flags(main->p1_label, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->p1_label, sg_new_gstr("Player 1", get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	main->p2_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->p2_label,
		sg_recti(show->win_w - MAIN_SCENE_MARGIN * 2,
				show->win_h - MAIN_SCENE_MARGIN - 25, 0, 0));
	sg_set_flags(main->p2_label, SG_LOCK_TOP
		| SG_LOCK_RIGHT | SG_LOCK_SIZE
		| SG_ALIGN_LEFT);
	sg_set_label_text(main->p2_label, sg_new_gstr("Player 2", get_resource_path(FILLER_FONT), 20));
	main->vs_label = sg_create_label(main->ptr);
	sg_set_component_boundaries(main->vs_label,
		sg_recti(show->win_w / 2, show->win_h - MAIN_SCENE_MARGIN - 25, 0, 0));
	sg_set_flags(main->vs_label, SG_LOCK_TOP
		| SG_LOCK_SIZE);
	sg_set_label_text(main->vs_label, sg_new_gstr("vs", get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
}

static void				pause_button(void *component, t_component_data *data)
{
	SDL_Event	e;

	e.type = SDL_KEYDOWN;
	e.key.keysym.sym = SDLK_SPACE;
	SDL_PushEvent(&e);
}

static void				buttons(t_show *show, t_main_scene *main)
{
	main->pause_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->pause_button,
		sg_recti(show->win_w / 2, MAIN_SCENE_MARGIN + MAIN_SCENE_BOTTOM_HEIGHT / 2,
			200, MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->pause_button, SG_LOCK_BOTTOM | SG_LOCK_SIZE);
	sg_set_button_text(main->pause_button, sg_new_gstr("Pause", get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(main->pause_button, MAIN_SCENE_EDGE);
	sg_set_button_radius(main->pause_button, MAIN_SCENE_CORNER_RADIUS);
	sg_set_button_action(main->pause_button, &pause_button);
}

void					main_update_colors(t_show *show, t_main_scene *main)
{
	sg_set_rectangle_icolor(main->top_frame, show->gui.colors->background);
	sg_set_rectangle_ocolor(main->top_frame, show->gui.colors->main_text);
	sg_set_rectangle_icolor(main->bottom_frame, show->gui.colors->background);
	sg_set_rectangle_ocolor(main->bottom_frame, show->gui.colors->main_text);
	sg_set_label_color(main->p1_label, show->gui.colors->display_o);
	sg_set_label_color(main->p2_label, show->gui.colors->display_x);
	sg_set_label_color(main->vs_label, show->gui.colors->main_text);
	show_set_display_ocolor(main->display_frame, show->gui.colors->display_o);
	show_set_display_xcolor(main->display_frame, show->gui.colors->display_x);
	show_set_display_ecolor(main->display_frame, show->gui.colors->display_edge);
	show_set_display_gcolor(main->display_frame, show->gui.colors->display_grid);
	sg_set_button_icolor(main->pause_button, show->gui.colors->background);
	sg_set_button_ocolor(main->pause_button, show->gui.colors->main_text);
	sg_set_button_hcolor(main->pause_button, show->gui.colors->background);
	sg_set_button_pcolor(main->pause_button, show->gui.colors->background);
	sg_set_button_text_color(main->pause_button, show->gui.colors->main_text);
}

void					init_main_scene(t_show *show, t_main_scene *main)
{

	main->ptr = sg_new_scene(show->window);
	frames(show, main);
	labels(show, main);
	display(show, main);
	buttons(show, main);
	main_update_colors(show, main);
}
