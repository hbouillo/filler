/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choke_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:01:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/18 01:13:55 by hbouillo         ###   ########.fr       */
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
		}
	}
	if (last_data)
		free(last_data);
	last_data = ft_strdup(map->data);
	return (pos);
}

static int			touched_right(t_map *map, t_player *player)
{
	int				i;

	i = 0;
	while (++i <= map->size.y)
	{
		if (map->data[i * map->size.x - 1] == player->place_char)
			return (1);
	}
	return (0);
}

static t_pos		carli_is_annoying_af(t_map *map, t_player *player)
{
	t_pos			pos;

	if (!touched_right(map, player))
	{
		pos.x = map->size.x * 2;
		pos.y = player->my_spawn.y;
	}
	else
	{
		pos.x = 0;
		pos.y = -map->size.y * 5;
	}
	return (pos);
}

static t_pos		*nextpos(t_sol *sol, t_map *map, t_player *player)
{
	t_arm			head;

	if (map->size.x * map->size.y < 300 && player->my_spawn.x > map->size.x / 2)
		head.point = carli_is_annoying_af(map, player);
	else
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
	free_sol(sol);
	return (pos);
}
