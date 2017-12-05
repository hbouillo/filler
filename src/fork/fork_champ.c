/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:30:58 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/05 21:08:43 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "fork_champ.h"

t_fork				*getfork(t_player *player, t_map *map)
{
	static t_fork	*fork;

	if (!fork)
	{
		if (!(fork = (t_fork *)malloc(sizeof(t_fork))))
			exit(1);
		fork->status = FORK_BACK;
		fork->arm_r.point.x = player->my_spawn.x;
		fork->arm_r.point.y = player->my_spawn.y;
		fork->arm_r.dir.x = (player->enemy_spawn.x - fork->arm_r.point.x) * 10;
		fork->arm_r.dir.y = (player->enemy_spawn.y - fork->arm_r.point.y) * 10;
		fork->arm_r.dir.x = FORK_COS * fork->arm_r.dir.x - FORK_SIN * fork->arm_r.dir.y;
		fork->arm_r.dir.y = FORK_SIN * fork->arm_r.dir.x + FORK_COS * fork->arm_r.dir.y;
		fork->arm_l.point.x = player->my_spawn.x;
		fork->arm_l.point.y = player->my_spawn.y;
		fork->arm_l.dir.x = (player->enemy_spawn.x - fork->arm_l.point.x) * 10;
		fork->arm_l.dir.y = (player->enemy_spawn.y - fork->arm_l.point.y) * 10;
		fork->arm_l.dir.x = FORK_COS * fork->arm_l.dir.x + FORK_SIN * fork->arm_l.dir.y;
		fork->arm_l.dir.y = -FORK_SIN * fork->arm_l.dir.x + FORK_COS * fork->arm_l.dir.y;
		fork->arm_back.point.x = player->my_spawn.x;
		fork->arm_back.point.y = player->my_spawn.y;
		fork->arm_back.dir.x = -(player->enemy_spawn.x - fork->arm_back.point.x) * 10;
		fork->arm_back.dir.y = -(player->enemy_spawn.y - fork->arm_back.point.y) * 10;
	}
	return (fork);
}

static int			is_back_safe(t_map *map, t_player *player)
{
	int				i;

	i = -1;
	while (++i < map->size.x)
	{
		if (map->data[i] == player->place_char)
			return (1);
		if (map->data[(map->size.y - 1) * map->size.x + i] == player->place_char)
			return (1);
	}
	i = -1;
	while (++i < map->size.y)
	{
		if (map->data[i * map->size.x] == player->place_char)
			return (1);
		if (map->data[i * map->size.x + map->size.y - 1] == player->place_char)
			return (1);
	}
	return (0);
}

t_pos				*fork_nextpos(t_player *player, t_map *map, t_piece *piece)
{
	t_pos			*pos;
	t_fork			*fork;
	t_sol			*sol;

	fork = getfork(player, map);
//	fork->arm.dir.x = FORK_COS_DEV * fork->arm.dir.x - FORK_SIN_DEV * fork->arm.dir.y;
//	fork->arm.dir.y = FORK_SIN_DEV * fork->arm.dir.x + FORK_COS_DEV * fork->arm.dir.y;
	sol = analyse(player, map, piece);
	if (fork->status == FORK_BACK)
	{
		if (is_back_safe(map, player))
			fork->status = FORK_RIGHT;
		else
		{
			pos = get_arm_next_pos(sol, fork->arm_back);
			fork->arm_back.point = *pos;
		}
	}
	if (fork->status == FORK_RIGHT)
	{
		pos = get_arm_next_pos(sol, fork->arm_r);
		fork->arm_r.point = *pos;
		fork->status = FORK_LEFT;
	}
	else if (fork->status == FORK_LEFT)
	{
		pos = get_arm_next_pos(sol, fork->arm_l);
		fork->arm_l.point = *pos;
		fork->status = FORK_RIGHT;
	}
	return (pos);
}
