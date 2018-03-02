/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_setters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 04:26:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/20 20:15:06 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rectangle.h"

void			sg_set_rectangle_icolor(void *component, t_color color)
{
	t_rectangle	*rectangle;

	rectangle = (t_rectangle *)((t_component *)component)->data.data;
	rectangle->icolor = color;
}

void			sg_set_rectangle_ocolor(void *component, t_color color)
{
	t_rectangle	*rectangle;

	rectangle = (t_rectangle *)((t_component *)component)->data.data;
	rectangle->ocolor = color;
}

void			sg_set_rectangle_edge(void *component, int edge)
{
	t_rectangle	*rectangle;

	rectangle = (t_rectangle *)((t_component *)component)->data.data;
	rectangle->edge = edge;
}

void			sg_set_rectangle_radius(void *component, int radius)
{
	t_rectangle	*rectangle;

	rectangle = (t_rectangle *)((t_component *)component)->data.data;
	rectangle->radius = radius;
}
