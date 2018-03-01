/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woo_grade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 01:24:46 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:03:05 by hbouillo         ###   ########.fr       */
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

static int		check_pos_value(char *grademap, t_map *map, t_pos pos,
					char value)
{
	if ((pos.x > 0 && grademap[(pos.y) * map->size.x + pos.x - 1]
			== value) ||
		(pos.x < map->size.x - 1 && grademap[(pos.y) * map->size.x + pos.x + 1]
			== value) ||
		(pos.y > 0 && grademap[(pos.y - 1) * map->size.x + pos.x]
			== value) ||
		(pos.y < map->size.y - 1 && grademap[(pos.y + 1) * map->size.x + pos.x]
			== value))
		return (1);
	return (0);
}

static int		grade_pos(char *grademap, t_map *map, t_player *player,
					t_pos pos)
{
	int			grade;

	grade = 0;
	if (check_pos_value(grademap, map, pos, player->place_char))
	{
		grade++;
		grademap[(map->size.x) * pos.y + pos.x] = 1;
	}
	if (check_pos_value(grademap, map, pos, player->enemy_char))
	{
		grade--;
		grademap[(map->size.x) * pos.y + pos.x] = 2;
	}
	return (grade);
}

int				woo_grade_map(t_map *map, char *grademap, t_player *player)
{
	int			done;
	int			grade;
	int			pass;
	t_pos		counter;

	pass = 0;
	grade = 0;
	done = 0;
	while (!done && ++pass)
	{
		done = 1;
		counter.x = -1;
		while (++counter.x < map->size.x)
		{
			counter.y = -1;
			while (++counter.y < map->size.y)
				if (grademap[(map->size.x) * counter.y + counter.x] == '.')
				{
					grade += pass * grade_pos(grademap, map, player, counter);
					done = 0;
				}
		}
		reset(grademap, map->size, player);
	}
	return (grade);
}
