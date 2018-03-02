/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_setters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 05:13:41 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:36:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./component.h"

void		sg_set_component_boundaries(void *component, t_rect bounds)
{
	((t_component *)component)->bounds = bounds;
	((t_component *)component)->data.full_draw = 1;
}

void		sg_set_component_position(void *component, t_pos pos)
{
	((t_component *)component)->bounds.x = pos.x;
	((t_component *)component)->bounds.y = pos.y;
}

void		sg_set_component_size(void *component, t_size size)
{
	((t_component *)component)->bounds.w = size.w;
	((t_component *)component)->bounds.h = size.h;
	((t_component *)component)->data.full_draw = 1;
}

void		sg_set_component_draw(void *component,
				void (*draw)(void *component, t_component_data *data,
					t_rect bounds))
{
	if (!((t_component *)component)->draw)
		((t_component *)component)->draw = draw;
}

void		sg_set_component_event(void *component,
				void (*event)(void *component, t_component_data *data,
					SDL_Event e))
{
	if (!((t_component *)component)->event)
		((t_component *)component)->event = event;
}
