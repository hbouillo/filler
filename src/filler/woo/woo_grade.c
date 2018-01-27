/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woo_grade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 01:24:46 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/27 06:34:45 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woo_champ.h"

static void		reset(char *grademap, t_size mapsize, t_player *player)
{
	int				x;
	int				y;

	x = -1;
	while (++x < mapsize.x)
	{
		y = -1;
		while (++y < mapsize.y)
		{
			if (grademap[y * mapsize.x + x] == 1)
				grademap[y * mapsize.x + x] = player->place_char;
			else if (grademap[y * mapsize.x + x] == 2)
				grademap[y * mapsize.x + x] = player->enemy_char;
		}
	}
}

static int		grade_pos(char *grademap, t_map *map, t_player *player, t_pos pos)
{
	int			grade;

	grade = 0;
	if ((pos.x > 0 && grademap[(pos.y) * map->size.x + pos.x - 1] == player->place_char) ||
		(pos.x < map->size.x - 1 && grademap[(pos.y) * map->size.x + pos.x + 1] == player->place_char) ||
		(pos.y > 0 && grademap[(pos.y - 1) * map->size.x + pos.x] == player->place_char) ||
		(pos.y < map->size.y - 1 && grademap[(pos.y + 1) * map->size.x + pos.x] == player->place_char))
	{
		grade++;
		grademap[(map->size.x) * pos.y + pos.x] = 1;
	}
	if ((pos.x > 0 && grademap[(pos.y) * map->size.x + pos.x - 1] == player->enemy_char) ||
		(pos.x < map->size.x - 1 && grademap[(pos.y) * map->size.x + pos.x + 1] == player->enemy_char) ||
		(pos.y > 0 && grademap[(pos.y - 1) * map->size.x + pos.x] == player->enemy_char) ||
		(pos.y < map->size.y - 1 && grademap[(pos.y + 1) * map->size.x + pos.x] == player->enemy_char))
	{
		grade--;
		grademap[(map->size.x) * pos.y + pos.x] = 2;
	}
	return (grade);
}

//TODO: Get rid of all those damn loops. 1 loop, gets X positions, then only works on nearby positions per loop. Huge perfs gains...
int				woo_grade_map(t_map *map, char *grademap, t_player *player)
{
	int			done;
	int			grade;
	int			pass;
	t_pos			counter;

	pass = 1;
	grade = 0;
	done = 0;
	while (!done)
	{
		done = 1;
		counter.x = -1;
		while (++counter.x < map->size.x)
		{
			counter.y = -1;
			while (++counter.y < map->size.y)
			{
				if (grademap[(map->size.x) * counter.y + counter.x] == '.')
				{
					grade += pass * grade_pos(grademap, map, player, counter);
					done = 0;
				}
			}
		}
		pass++;
		reset(grademap, map->size, player);
	}
	return (grade);
}
