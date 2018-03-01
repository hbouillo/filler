/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:38:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:09:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_map(t_map **map)
{
	char	*line;
	char	**split;

	ft_gnl(0, &line);
	if (line && !*line)
	{
		free(line);
		return (FILLER_END_PARSE);
	}
	if (!(split = ft_strsplit(line, ' ')))
		exit(1);
	free(line);
	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	if (!ft_strequ(split[0], "Plateau"))
	{
		ft_chartabfree(split);
		return (FILLER_ERR_PARSE);
	}
	(*map)->size.y = ft_atoi(split[1]);
	(*map)->size.x = ft_atoi(split[2]);
	ft_chartabfree(split);
	return (0);
}

static void	set_enemy_spawn(t_player *player, int i, int j)
{
	player->enemy_spawn.x = j;
	player->enemy_spawn.y = i;
}

static void	set_my_spawn(t_player *player, int i, int j)
{
	player->enemy_spawn.x = j;
	player->enemy_spawn.y = i;
}

int			parse_map(t_map *map, t_player *player)
{
	char	*line;
	int		i;
	int		j;

	skip_line(0);
	if (!(map->data = (char *)ft_memalloc(sizeof(char) *
		(map->size.x * map->size.y + 1))))
		exit(1);
	i = -1;
	while (++i < map->size.y)
	{
		ft_gnl(0, &line);
		ft_strcpy(map->data + map->size.x * i, line + 4);
		j = -1;
		if (player->enemy_spawn.x < 0 || player->my_spawn.x < 0)
			while (line[++j])
			{
				if (line[j] == player->enemy_char)
					set_enemy_spawn(player, i, j);
				if (line[j] == player->place_char)
					set_my_spawn(player, i, j);
			}
		free(line);
	}
	return (0);
}

int			init_piece(t_piece **piece)
{
	char	*line;
	char	**split;

	ft_gnl(0, &line);
	if (!(split = ft_strsplit(line, ' ')))
		exit(1);
	free(line);
	if (!(*piece = (t_piece *)malloc(sizeof(t_piece))))
		exit(1);
	if (!ft_strequ(split[0], "Piece"))
	{
		ft_chartabfree(split);
		return (FILLER_ERR_PARSE);
	}
	(*piece)->size.y = ft_atoi(split[1]);
	(*piece)->size.x = ft_atoi(split[2]);
	(*piece)->compact_size.y = -1;
	(*piece)->compact_size.x = -1;
	(*piece)->offset.y = (*piece)->size.y;
	(*piece)->offset.x = (*piece)->size.x;
	ft_chartabfree(split);
	return (0);
}
