/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 06:41:15 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:27:58 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_scene.h"

static void				handle_end(void *component, t_component_data *data)
{
	SDL_Event	e;

	component = NULL;
	data = NULL;
	e.type = SDL_KEYDOWN;
	e.key.keysym.sym = SDLK_END;
	SDL_PushEvent(&e);
}

void					end_button(t_show *show, t_main_scene *main)
{
	if (!(main->end_button = sg_create_button(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->end_button,
		sg_recti(show->win_w - MAIN_SCENE_MARGIN, MAIN_SCENE_MARGIN,
			MAIN_SCENE_FRAME_BUTTON_WIDTH, MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->end_button, SG_LOCK_BOTTOM | SG_LOCK_RIGHT |
		SG_LOCK_SIZE | SG_ALIGN_TOP | SG_ALIGN_LEFT);
	sg_set_button_text(main->end_button, sg_new_gstr("End",
		get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(main->end_button, MAIN_SCENE_EDGE);
	sg_set_button_radius(main->end_button, MAIN_SCENE_CORNER_RADIUS);
	sg_set_button_action(main->end_button, &handle_end);
}
