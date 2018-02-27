/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slower_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 06:41:15 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/27 07:22:13 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

static void				handle_slower(void *component, t_component_data *data)
{
	SDL_Event	e;

	e.type = SDL_KEYDOWN;
	e.key.keysym.sym = SDLK_DOWN;
	SDL_PushEvent(&e);
}

void					slower_button(t_show *show, t_main_scene *main)
{
	main->slower_button = sg_create_button(main->ptr);
	sg_set_component_boundaries(main->slower_button,
		sg_recti(MAIN_SCENE_MARGIN * 3 + MAIN_SCENE_FRAME_BUTTON_WIDTH * 2, MAIN_SCENE_MARGIN,
			MAIN_SCENE_BUTTON_HEIGHT, MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->slower_button, SG_LOCK_BOTTOM | SG_LOCK_LEFT | SG_LOCK_SIZE | SG_ALIGN_TOP | SG_ALIGN_RIGHT);
	sg_set_button_text(main->slower_button, sg_new_gstr("-", get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(main->slower_button, MAIN_SCENE_EDGE);
	sg_set_button_radius(main->slower_button, MAIN_SCENE_CORNER_RADIUS);
	sg_set_button_action(main->slower_button, &handle_slower);
}
