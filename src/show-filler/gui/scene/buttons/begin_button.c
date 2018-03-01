/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 06:41:15 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:27:52 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_scene.h"

static void				handle_begin(void *component, t_component_data *data)
{
	SDL_Event	e;

	component = NULL;
	data = NULL;
	e.type = SDL_KEYDOWN;
	e.key.keysym.sym = SDLK_BACKSPACE;
	SDL_PushEvent(&e);
}

void					begin_button(t_show *show, t_main_scene *main)
{
	show = NULL;
	if (!(main->begin_button = sg_create_button(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->begin_button,
		sg_recti(MAIN_SCENE_MARGIN, MAIN_SCENE_MARGIN,
			MAIN_SCENE_FRAME_BUTTON_WIDTH, MAIN_SCENE_BUTTON_HEIGHT));
	sg_set_flags(main->begin_button, SG_LOCK_BOTTOM | SG_LOCK_LEFT |
		SG_LOCK_SIZE | SG_ALIGN_TOP | SG_ALIGN_RIGHT);
	sg_set_button_text(main->begin_button, sg_new_gstr("Begin",
		get_resource_path(FILLER_FONT), FILLER_TOP_FONT_SIZE));
	sg_set_button_edge(main->begin_button, MAIN_SCENE_EDGE);
	sg_set_button_radius(main->begin_button, MAIN_SCENE_CORNER_RADIUS);
	sg_set_button_action(main->begin_button, &handle_begin);
}
