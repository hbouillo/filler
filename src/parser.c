/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:38:22 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:59:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_map(t_map **map)
{
	char	*line;
	char	**split;

	ft_gnl(0, &line);
	if (!(split = ft_strsplit(line, ' ')))
		exit(1);
	free(line);
	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	if (!ft_strequ(split[0], "Plateau"))
		return (FILLER_ERR_PARSE);
	(*map)->size.y = ft_atoi(split[1]);
	(*map)->size.x = ft_atoi(split[2]);
	return (0);
}

int			parse_map(t_map *map)
{
	char	*line;
	int		i;

	skip_line(0, &line);
	if (!(map->data = (char *)malloc(sizeof(char) * (map->size.x * map->size.y))))
		exit(1);
	i = -1;
	while (++i < map->size.y)
	{
		ft_gnl(0, &line);
		ft_strcpy(map->data + map->size.x * i, line + 4);
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
		return (FILLER_ERR_PARSE);
	(*piece)->size.y = ft_atoi(split[1]);
	(*piece)->size.x = ft_atoi(split[2]);
	(*piece)->compact_size.y = -1;
	(*piece)->compact_size.x = -1;
	(*piece)->offset.y = (*piece)->size.y;
	(*piece)->offset.x = (*piece)->size.x;
	return (0);
}

static int	analyse_piece(t_piece *piece)
{
	int		x;
	int		y;

	x = -1;
	while (++x < piece->size.x)
	{
		y = -1;
		while (++y < piece->size.y)
		{
			if (piece->data[piece->size.x * y + x] != '.')
			{
				piece->offset.x = ft_nbrmin(piece->offset.x, x);
				piece->offset.y = ft_nbrmin(piece->offset.y, y);
				piece->compact_size.x = ft_nbrmax(piece->compact_size.x, x);
				piece->compact_size.y = ft_nbrmax(piece->compact_size.y, y);
			}
		}
	}
	piece->compact_size.x = piece->compact_size.x - piece->offset.x + 1;
	piece->compact_size.y = piece->compact_size.y - piece->offset.y + 1;
	//dprintf(2, "\n||| COMPACT %d, %d, OFFSET %d, %d |||\n", piece->compact_size.x, piece->compact_size.y, piece->offset.x, piece->offset.y);
	return (0);
}
int			parse_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (!(piece->data = (char *)malloc(sizeof(char) * (piece->size.x * piece->size.y))))
		exit(1);
	i = -1;
	while (++i < piece->size.y)
	{
		ft_gnl(0, &line);
		ft_strcpy(piece->data + piece->size.x * i, line);
	}
	analyse_piece(piece);
	return (0);
}
