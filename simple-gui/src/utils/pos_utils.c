/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 04:57:27 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:57:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p_sg.h"

t_pos					sg_posf(float x, float y)
{
	t_pos				pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos					sg_posf_pad(float x, float y)
{
	t_pos				pos;
	float				fx;
	float				fy;

	fx = 2.0 / ((float)sg_get_shared_data()->window_w);
	fy = 2.0 / ((float)sg_get_shared_data()->window_h);
	pos.x = ((float)((int)((x + 1.0) / fx))) * fx - 1.0;
	pos.y = ((float)((int)((y + 1.0) / fy))) * fy - 1.0;
	return (pos);
}

t_pos					sg_posi(int x, int y)
{
	t_pos				pos;
	float				fx;
	float				fy;

	fx = 2.0 / ((float)sg_get_shared_data()->window_w);
	fy = 2.0 / ((float)sg_get_shared_data()->window_h);
	pos.x = ((float)x) * fx - 1.0;
	pos.y = ((float)y) * fy - 1.0;
	return (pos);
}
