/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choke_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:01:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/11 02:32:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choke_champ.h"
#include <stdio.h>

static t_pos		last_enemy_pos(t_map *map, t_player *player)
{
	static char		*last_data;
	int				i;
	t_pos			pos;

	i = -1;
	pos.x = 0;
	pos.y = 0;
	while (++i < map->size.x * map->size.y)
	{
		if ((!last_data && map->data[i] == player->enemy_char) ||
			(last_data && last_data[i] == '.' &&
			map->data[i] == player->enemy_char))
		{
			pos.x = i % map->size.x;
			pos.y = i / map->size.x;
			break;
		}
	}
	last_data = ft_strdup(map->data);
	return (pos);
}

static t_pos		*nextpos(t_sol *sol, t_map *map, t_player *player)
{
	t_arm			head;

	head.point = last_enemy_pos(map, player);
	head.dir.x = 0;
	head.dir.y = 0;
	map = 0;
	player = 0;
	return (get_arm_next_pos(sol, head));
}

t_pos				*choke_nextpos(t_player *player, t_map *map, t_piece *piece)
{
	t_pos			*pos;
	t_sol			*sol;

	sol = analyse(player, map, piece);
	pos = NULL;
	while (!pos)
		pos = nextpos(sol, map, player);
	return (pos);
}
