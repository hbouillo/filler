/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 01:17:16 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 02:52:30 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_sg.h"

static void			handle_component_expand(t_component *component, t_pos f)
{
	t_shared		*shared;
	float			tmp;

	shared = sg_get_shared_data();
	if (sg_has_flags(component, SG_LOCK_BOTTOM))
	{
		tmp = (component->bounds.y + 1.0) * f.y - 1.0;
		if (sg_has_flags(component, SG_LOCK_TOP))
			component->bounds.h = ((component->bounds.y +
				component->bounds.h) - 1.0) * f.y + 1.0 - tmp;
		component->bounds.y = tmp;
	}
	else if (sg_has_flags(component, SG_LOCK_TOP))
		component->bounds.y = (component->bounds.y - 1.0) * f.y + 1.0;
	if (sg_has_flags(component, SG_LOCK_LEFT))
	{
		tmp = (component->bounds.x + 1.0) * f.x - 1.0;
		if (sg_has_flags(component, SG_LOCK_RIGHT))
			component->bounds.w = ((component->bounds.x +
				component->bounds.w) - 1.0) * f.x + 1.0 - tmp;
		component->bounds.x = tmp;
	}
	else if (sg_has_flags(component, SG_LOCK_RIGHT))
		component->bounds.x = (component->bounds.x - 1.0) * f.x + 1.0;
}

static void			handle_component_resize(t_component *component)
{
	t_shared		*shared;
	t_pos			f;

	shared = sg_get_shared_data();
	f.x = ((float)shared->last_window_w) / ((float)shared->window_w);
	f.y = ((float)shared->last_window_h) / ((float)shared->window_h);
	component->data.full_draw = 1;
	if (sg_has_flags(component, SG_LOCK_WIDTH))
		component->bounds.w *= f.x;
	if (sg_has_flags(component, SG_LOCK_HEIGHT))
		component->bounds.h *= f.y;
	if (sg_has_flags(component, SG_LOCK_MID_X))
		component->bounds.x = (component->bounds.x) * f.x;
	if (sg_has_flags(component, SG_LOCK_MID_Y))
		component->bounds.y = (component->bounds.y) * f.y;
	handle_component_expand(component, f);
}

static void			component_event(t_component *component, SDL_Event e,
						int mode)
{
	t_rect			bounds;

	if (e.type == SDL_WINDOWEVENT &&
		e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		handle_component_resize(component);
	bounds = component->bounds;
	sg_align_bounds(&bounds, component->data.states);
	if (!component->hide && component->event &&
		mode == SG_MODE_ACTIVE && sg_get_shared_data()->mouse_init &&
		sg_is_in_rect(bounds, sg_get_shared_data()->mouse_pos))
	{
		component->data.states |= SG_HOVERED;
		if (e.type == SDL_MOUSEBUTTONDOWN)
			component->data.states |= SG_PRESSED;
		else if (e.type == SDL_MOUSEBUTTONUP)
			component->data.states &= ~SG_PRESSED;
		component->event(component, &(component->data), e);
	}
	else if (mode == SG_MODE_ACTIVE)
	{
		component->data.states &= ~SG_HOVERED;
		component->data.states &= ~SG_PRESSED;
	}
}

void				sg_event(void *scene, SDL_Event e, int mode)
{
	t_scene			*scene_s;
	t_llist			*queue;
	t_component		*component;

	scene_s = ((t_scene *)scene);
	queue = scene_s->queue;
	if (e.type == SDL_MOUSEMOTION)
		update_mouse(e.motion.x, e.motion.y);
	if (e.type == SDL_WINDOWEVENT &&
		e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		update_window((int)e.window.data1, (int)e.window.data2);
	while (queue)
	{
		component = (t_component *)queue->data;
		component_event(component, e, mode);
		queue = queue->next;
	}
}
