/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:45:57 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/05 16:57:16 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			dist2(t_pos point1, t_pos point2)
{
	int				dist;

	dist = (point2.x - point1.x) * (point2.x - point1.x) +
			(point2.y - point1.y) * (point2.y - point1.y);
	return (dist);
}

t_pos				*get_arm_next_pos(t_sol *sol, t_arm arm)
{
	t_pos	aim;
	t_pos	*best;
	int		smallest;
	int		tmp_dist;

	smallest = 0x7fffffff;
	aim = arm.point;
	aim.x += arm.dir.x;
	aim.y += arm.dir.y;

	if (!(best = (t_pos *)ft_memalloc(sizeof(t_pos))))
		exit(1);
	while(sol)
	{
		tmp_dist = dist2(sol->pos, aim);
		if (tmp_dist < smallest)
		{
			best->x = sol->pos.x;
			best->y = sol->pos.y;
			smallest = tmp_dist;
		}
		sol = sol->nxt;
	}
	return (best);
}
