/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woo_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:01:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:47:21 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woo_champ.h"
#include <stdio.h>

static int			evaluate_pos(t_pos pos, t_map *map, t_player *player,
						t_piece *piece)
{
	int				grade;
	char			*grademap;
	int				x;
	int				y;

	grade = 0;
	if (!(grademap = (char *)ft_memalloc(
		sizeof(char) * map->size.x * map->size.y + 1)))
		exit(1);
	ft_memcpy(grademap, map->data, map->size.x * map->size.y);
	x = -1;
	while (++x < piece->size.x)
	{
		y = -1;
		while (++y < piece->size.y)
		{
			if (piece->data[piece->size.x * y + x] == '*')
				grademap[(pos.y + y) * map->size.x + (pos.x + x)] =
					player->place_char;
		}
	}
	grade = woo_grade_map(map, grademap, player);
	free(grademap);
	return (grade);
}

static t_pos		*most_annoying_pos(t_sol *sol, t_map *map, t_player *player,
						t_piece *piece)
{
	t_pos			*pos;
	int				max_grade;
	int				tmp_grade;

	max_grade = 0x80000000;
	pos = NULL;
	while (sol)
	{
		tmp_grade = evaluate_pos(sol->pos, map, player, piece);
		if (tmp_grade > max_grade)
		{
			if (!pos && !(pos = (t_pos *)ft_memalloc(sizeof(t_pos))))
				exit(1);
			max_grade = tmp_grade;
			pos->x = sol->pos.x;
			pos->y = sol->pos.y;
		}
		sol = sol->nxt;
	}
	return (pos);
}

static t_pos		*nextpos(t_sol *sol, t_map *map, t_player *player,
						t_piece *piece)
{
	t_pos			*pos;

	pos = most_annoying_pos(sol, map, player, piece);
	return (pos);
}

t_pos				*woo_nextpos(t_player *player, t_map *map, t_piece *piece)
{
	t_pos			*pos;
	t_sol			*sol;

	sol = analyse(player, map, piece);
	pos = NULL;
	pos = nextpos(sol, map, player, piece);
	free_sol(sol);
	return (pos);
}
