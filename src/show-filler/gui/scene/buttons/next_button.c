/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 06:41:15 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/27 21:44:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_scene.h"

static void				handle_next(void *component, t_component_data *data)
{
	SDL_Event	e;

	component = NULL;
	data = NULL;
	e.type = SDL_KEYDOWN;
	e.key.keysym.sym = SDLK_RIGHT;
	SDL_PushEvent(&e);
}

void					next_button(t_show *show, t_main_scene *main)
{
	main->next_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->next_button,
		sg_recti(show->win_w - MAIN_SCENE_MARGIN * 2 - MAIN_SCENE_FRAME_BUTTON_WIDTH, MAIN_SCENE_MARGIN,
			MAIN_SCENE_FRAME_BUTTON_WIDTH, MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->next_button, SG_LOCK_BOTTOM | SG_LOCK_RIGHT | SG_LOCK_SIZE | SG_ALIGN_TOP | SG_ALIGN_LEFT);
	sg_set_button_text(main->next_button, sg_new_gstr("Next", get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(main->next_button, MAIN_SCENE_EDGE);
	sg_set_button_radius(main->next_button, MAIN_SCENE_CORNER_RADIUS);
	sg_set_button_action(main->next_button, &handle_next);
}
