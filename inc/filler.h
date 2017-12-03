/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:12:04 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/03 22:29:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>

# define FILLER_ERR_PARSE 1

typedef struct	s_player
{
	char		place_char;
	char		enemy_char;
}				t_player;

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef	t_size	t_pos;

typedef struct	s_map
{
	t_size		size;
	char		*data;
}				t_map;

typedef struct	s_piece
{
	t_size		size;
	t_size		compact_size;
	t_pos		offset;
	char		*data;
}				t_piece;

int				init_filler(void);

int				init_map(t_map **map);
int				parse_map(t_map *map);

int				init_piece(t_piece **piece);
int				parse_piece(t_piece *piece);

int				skip_line(int fd, char **line);

#endif
