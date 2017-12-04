/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:14:37 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 22:09:49 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

static int		can_place(t_player *player, t_map *map, t_piece *piece, t_pos *pos)
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
			tmp_map = map->data[(pos->y + i) * map->size.x + pos->x + j];
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

static t_pos	*place_first_good(t_player *player, t_map *map, t_piece *piece)
{
	t_pos		*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->y = -1;
	while (++(pos->y) <= map->size.y - piece->compact_size.y)
	{
		pos->x = -1;
		while (++(pos->x) <= map->size.x - piece->compact_size.x)
		{
			if (can_place(player, map, piece, pos))
			{
				pos->x -= piece->offset.x;
				pos->y -= piece->offset.y;
				return (pos);
			}
		}
	}
	pos->x = 0;
	pos->y = 0;
	return (pos);
}

static int		reply_filler(t_player *player, t_map *map, t_piece *piece)
{
	t_pos		*pos;

	pos = place_first_good(player, map, piece);
	ft_printf("%d %d\n", pos->y, pos->x);
	return (0);
}

static int		loop_filler(t_player *player)
{
	t_map		*map;
	t_piece		*piece;

	map = NULL;
	while (1)
	{
		if (init_map(&map))
			break ;
		parse_map(map);
		init_piece(&piece);
		parse_piece(piece);
		reply_filler(player, map, piece);
		free(map);
		free(piece);
	}
	return (0);
}

int				init_filler(void)
{
	char		*line;
	t_player	*player;

	line = NULL;
	player = NULL;
	while (!player)
	{
		ft_gnl(0, &line);
		if (line && *line == '$')
		{
			if (!(player = (t_player *)malloc(sizeof(t_player))))
				exit(1);
			if (line[10] == '1' || line[10] == '2')
			{
				player->place_char = line[10] == '1' ? 'O' : 'X';
				player->enemy_char = line[10] == '1' ? 'X' : 'O';
			}
			else
				return (FILLER_ERR_PARSE);
		}
	}
	loop_filler(player);
	return (0);
}
