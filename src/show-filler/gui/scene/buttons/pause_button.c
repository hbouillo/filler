/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 06:41:15 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/27 21:13:16 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_scene.h"

static void				handle_pause(void *component, t_component_data *data)
{
	SDL_Event	e;

	e.type = SDL_KEYDOWN;
	e.key.keysym.sym = SDLK_SPACE;
	SDL_PushEvent(&e);
}

void					pause_button(t_show *show, t_main_scene *main)
{
	main->pause_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->pause_button,
		sg_recti(show->win_w / 2, MAIN_SCENE_MARGIN,
			MAIN_SCENE_PAUSE_BUTTON_WIDTH, MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->pause_button, SG_LOCK_BOTTOM | SG_LOCK_SIZE | SG_ALIGN_TOP);
	sg_set_button_text(main->pause_button, sg_new_gstr("Pause", get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(main->pause_button, MAIN_SCENE_EDGE);
	sg_set_button_radius(main->pause_button, MAIN_SCENE_CORNER_RADIUS);
	sg_set_button_action(main->pause_button, &handle_pause);
}
