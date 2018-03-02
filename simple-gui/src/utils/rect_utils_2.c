/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 00:09:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 22:22:57 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p_sg.h"

t_rect					sg_rectf(float x, float y, float w, float h)
{
	t_rect				rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}

t_rect					sg_recti(int x, int y, int w, int h)
{
	t_rect				rect;
	float				fx;
	float				fy;

	fx = 2.0 / ((float)sg_get_shared_data()->window_w);
	fy = 2.0 / ((float)sg_get_shared_data()->window_h);
	rect.x = ((float)x) * fx - 1.0;
	rect.y = ((float)y) * fy - 1.0;
	rect.w = ((float)w) * fx;
	rect.h = ((float)h) * fy;
	return (rect);
}

t_rect					sg_rect(t_pos pos, t_size size)
{
	return (sg_rectf(pos.x, pos.y, size.w, size.h));
}
