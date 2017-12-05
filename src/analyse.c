/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:29:05 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/05 16:17:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		can_place(t_player *player, t_map *map, t_piece *piece, t_pos const pos)
{
	int		i;
	int		j;
	char	tmp_map;
	char	tmp_pc;
	int		count;

	i = -1;
	count = 0;
	while (++i < piece->compact_size.y)
	{
		j = -1;
		while (++j < piece->compact_size.x)
		{
			tmp_map = map->data[(pos.y + i) * map->size.x + pos.x + j];
			tmp_pc = piece->data[(piece->offset.y + i) * piece->size.x + piece->offset.x + j];
			if ((tmp_pc != '.' && tmp_map == player->enemy_char) ||
				(tmp_pc != '.' && tmp_map == player->place_char && count > 0))
				return (0);
			else if (tmp_pc != '.' && tmp_map == player->place_char)
				count++;
		}
	}
	return (count > 0 ? 1 : 0);
}

static int		add_pos(t_sol **sol, t_pos const pos)
{
	t_sol		*head;
	t_sol		*new;

	if (!(new = (t_sol *)ft_memalloc(sizeof(t_sol))))
		exit(1);
	new->pos.x = pos.x;
	new->pos.y = pos.y;
	if (!*sol)
	{
		*sol = new;
		return (0);
	}
	head = *sol;
	while (head->nxt)
		head = head->nxt;
	head->nxt = new;
	return (0);
}

t_sol			*analyse(t_player *player, t_map *map, t_piece *piece)
{
	t_sol		*sol;
	t_pos		pos;
	t_pos		i;

	sol = NULL;
	i.y = -1;
	while (++(i.y) <= map->size.y - piece->compact_size.y)
	{
		i.x = -1;
		while (++(i.x) <= map->size.x - piece->compact_size.x)
		{
			if (can_place(player, map, piece, i))
			{
				pos.x = i.x - piece->offset.x;
				pos.y = i.y - piece->offset.y;
				add_pos(&sol, pos);
			}
		}
	}
	if (!sol)
	{
		pos.x = 0;
		pos.y = 0;
		add_pos(&sol, pos);
	}
	return (sol);
}
