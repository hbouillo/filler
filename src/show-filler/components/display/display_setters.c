/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:13:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/22 05:42:20 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

void			show_set_display_ocolor(void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->ocolor = color;
}

void			show_set_display_xcolor(void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->xcolor = color;
}

void			show_set_display_ecolor(void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->ecolor = color;
}

void			show_set_display_gcolor(void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->gcolor = color;
}

void			show_set_display_edge(void *component, int edge)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->edge = edge;
}
