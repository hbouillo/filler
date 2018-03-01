/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:09:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:13:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	return (0);
}

int			parse_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (!(piece->data = (char *)ft_memalloc(sizeof(char) *
		(piece->size.x * piece->size.y + 1))))
		exit(1);
	i = -1;
	while (++i < piece->size.y)
	{
		ft_gnl(0, &line);
		ft_strcpy(piece->data + piece->size.x * i, line);
		free(line);
	}
	analyse_piece(piece);
	return (0);
}
