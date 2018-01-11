/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:12:04 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/11 04:43:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>

# define FILLER_ERR_PARSE 1
# define FILLER_END_PARSE 1

typedef struct		s_size
{
	int				x;
	int				y;
}					t_size;

typedef	t_size		t_pos;

typedef t_pos		t_vec2;

typedef struct		s_player
{
	char			place_char;
	char			enemy_char;
	t_pos			enemy_spawn;
	t_pos			my_spawn;
}					t_player;

typedef struct		s_arm
{
	t_pos			point;
	t_vec2			dir;
}					t_arm;

typedef struct		s_map
{
	t_size			size;
	char			*data;
}					t_map;

typedef struct		s_sol
{
	t_pos			pos;
	struct s_sol	*nxt;
}					t_sol;

typedef struct		s_piece
{
	t_size			size;
	t_size			compact_size;
	t_pos			offset;
	char			*data;
}					t_piece;

int					init_filler(void);

int					init_map(t_map **map);
int					parse_map(t_map *map, t_player *player);

int					init_piece(t_piece **piece);
int					parse_piece(t_piece *piece);

int					skip_line(int fd);

t_sol				*analyse(t_player *player, t_map *map, t_piece *piece);
void				free_sol(t_sol *sol);

t_pos				*get_arm_next_pos(t_sol *sol, t_arm arm);

/*
** STRATEGIES
*/

t_pos				*dumb1_nextpos(t_player *player, t_map *map, t_piece *piece);
t_pos				*dumb2_nextpos(t_player *player, t_map *map, t_piece *piece);

t_pos				*fork_nextpos(t_player *player, t_map *map, t_piece *piece);
t_pos				*choke_nextpos(t_player *player, t_map *map, t_piece *piece);

#endif
