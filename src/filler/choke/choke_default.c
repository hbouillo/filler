/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choke_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 06:10:08 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/20 06:41:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choke_champ.h"

void				set_arm(t_arm *arm, int x, int y)
{
	arm->dir.x = 0;
	arm->dir.y = 0;
	arm->point.x = x;
	arm->point.y = y;
}

t_pos				*default_pos(t_sol *sol, t_map *map, t_player *player,
						t_piece *piece)
{
	t_arm			default_arm;
	int				tmp_dist;

	tmp_dist = 0;
	tmp_dist = player->my_spawn.x;
	set_arm(&default_arm, 0, player->my_spawn.y);
	if (player->my_spawn.y > tmp_dist)
	{
		tmp_dist = player->my_spawn.y;
		set_arm(&default_arm, player->my_spawn.x, 0);
	}
	if (map->size.x - player->my_spawn.x > tmp_dist)
	{
		tmp_dist = map->size.x - player->my_spawn.x;
		set_arm(&default_arm, map->size.x, player->my_spawn.y);
	}
	if (map->size.y - player->my_spawn.y > tmp_dist)
	{
		tmp_dist = map->size.y - player->my_spawn.y;
		set_arm(&default_arm, player->my_spawn.x, map->size.y);
	}
	default_arm.point.x = map->size.x / 4;
	default_arm.point.y = 0;
	return (get_arm_next_pos(sol, default_arm));
}
