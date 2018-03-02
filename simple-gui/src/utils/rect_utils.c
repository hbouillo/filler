/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:22:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/21 01:36:25 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p_sg.h"

void			sg_rect_to_vec2buf(t_rect rect, float *buf)
{
	buf[0] = rect.x;
	buf[1] = rect.y;
	buf[2] = rect.x + rect.w;
	buf[3] = rect.y;
	buf[4] = rect.x;
	buf[5] = rect.y + rect.h;
	buf[6] = rect.x + rect.w;
	buf[7] = rect.y + rect.h;
}

int				sg_is_in_rect(t_rect rect, t_pos pos)
{
	return ((pos.x > rect.x && pos.x < rect.x + rect.w &&
			pos.y > rect.y && pos.y < rect.y + rect.h) ? 1 : 0);
}

t_size			sg_sizef(float w, float h)
{
	t_size		size;

	size.w = w;
	size.h = h;
	return (size);
}

t_size			sg_sizei(int w, int h)
{
	t_size		size;
	float		fx;
	float		fy;

	fx = 2.0 / ((float)sg_get_shared_data()->window_w);
	fy = 2.0 / ((float)sg_get_shared_data()->window_h);
	size.w = ((float)w) * fx;
	size.h = ((float)h) * fy;
	return (size);
}

void			sg_align_bounds(t_rect *bounds, int alignement)
{
	bounds->x -= bounds->w / 2;
	bounds->y -= bounds->h / 2;
	if (alignement & SG_ALIGN_RIGHT)
		bounds->x += bounds->w / 2;
	if (alignement & SG_ALIGN_LEFT)
		bounds->x += -bounds->w / 2;
	if (alignement & SG_ALIGN_TOP)
		bounds->y += bounds->h / 2;
	if (alignement & SG_ALIGN_BOTTOM)
		bounds->y += -bounds->h / 2;
}
