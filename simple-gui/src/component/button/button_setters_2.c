/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_setters_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 06:08:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/22 21:15:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./button.h"

void		sg_set_button_edge(void *component, int edge)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->edge = edge;
}

void		sg_set_button_radius(void *component, int radius)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->radius = radius;
}

void		sg_set_button_action(void *component,
				void (*button_action)(void *component, t_component_data *data))
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->button_action = button_action;
}

void		sg_set_button_text_color(void *component, t_color font_color)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->font_color = font_color;
}
