/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:14:37 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/05 20:29:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

static int		reply_filler(t_player *player, t_map *map, t_piece *piece)
{
	t_pos		*pos;

	pos = fork_nextpos(player, map, piece);
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
		parse_map(map, player);
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
				player->enemy_spawn.x = -1;
				player->enemy_spawn.y = -1;
				player->my_spawn.x = -1;
				player->my_spawn.y = -1;
			}
			else
				return (FILLER_ERR_PARSE);
		}
	}
	loop_filler(player);
	return (0);
}
