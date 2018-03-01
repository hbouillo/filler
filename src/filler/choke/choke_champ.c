/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choke_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:01:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:42:16 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choke_champ.h"
#include <stdio.h>

static int			subgrade(t_pos pos, t_map *map, t_player *player, t_pos tmp)
{
	int				subgrade;

	subgrade = 0;
	if (map->data[ft_nbrmax(0, pos.y + tmp.y - 1) * map->size.x
		+ (pos.x + tmp.x)] == player->enemy_char)
		subgrade += GRADE_PROXIMITY;
	if (map->data[ft_nbrmin(map->size.y - 1, pos.y + tmp.y + 1)
		* map->size.x + (pos.x + tmp.x)] == player->enemy_char)
		subgrade += GRADE_PROXIMITY;
	if (map->data[(pos.y + tmp.y) * map->size.x +
		ft_nbrmax(0, (pos.x + tmp.x - 1))] == player->enemy_char)
		subgrade += GRADE_PROXIMITY;
	if (map->data[(pos.y + tmp.y) * map->size.x +
		ft_nbrmin(map->size.x - 1, (pos.x + tmp.x + 1))]
		== player->enemy_char)
		subgrade += GRADE_PROXIMITY;
	subgrade *= subgrade;
	return (subgrade);
}

static int			evaluate_pos(t_pos pos, t_map *map, t_player *player,
						t_piece *piece)
{
	int				grade;
	t_pos			tmp;

	grade = 0;
	tmp.x = -1;
	while (++tmp.x < piece->size.x)
	{
		tmp.y = -1;
		while (++tmp.y < piece->size.y)
		{
			if (piece->data[tmp.y * piece->size.x + tmp.x] == '*')
			{
				grade += subgrade(pos, map, player, tmp);
			}
		}
	}
	return (grade);
}

static t_pos		*most_annoying_pos(t_sol *sol, t_map *map, t_player *player,
						t_piece *piece)
{
	t_pos			*pos;
	int				max_grade;
	int				tmp_grade;

	max_grade = 0;
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
	if (!pos)
		pos = default_pos(sol, map, player);
	return (pos);
}

t_pos				*choke_nextpos(t_player *player, t_map *map, t_piece *piece)
{
	t_pos			*pos;
	t_sol			*sol;

	sol = analyse(player, map, piece);
	pos = NULL;
	pos = nextpos(sol, map, player, piece);
	free_sol(sol);
	return (pos);
}
