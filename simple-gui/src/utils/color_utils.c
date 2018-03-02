/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 06:23:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:43:52 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sg.h"

t_color			sg_colorf(float r, float g, float b, float a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_color			sg_colori(int r, int g, int b, int a)
{
	t_color	color;

	color.r = ((float)r) / 255.0;
	color.g = ((float)g) / 255.0;
	color.b = ((float)b) / 255.0;
	color.a = ((float)a) / 255.0;
	return (color);
}

/*
** Color from hex
*/

t_color			sg_color(int hexcolor)
{
	t_color	color;

	color.a = 1.0 - ((float)((hexcolor & 0xFF000000) >> 24)) / 255.0;
	color.r = ((float)((hexcolor & 0xFF0000) >> 16)) / 255.0;
	color.g = ((float)((hexcolor & 0xFF00) >> 8)) / 255.0;
	color.b = ((float)((hexcolor & 0xFF))) / 255.0;
	return (color);
}
