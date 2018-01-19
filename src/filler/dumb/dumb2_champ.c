/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb2_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:22:41 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/05 15:38:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos				*dumb2_nextpos(t_player *player, t_map *map, t_piece *piece)
{
	t_sol		*sol;
	t_pos		*pos;

	if (!(pos = (t_pos *)ft_memalloc(sizeof(t_pos))))
		exit(1);
	sol = analyse(player, map, piece);
	while (sol->nxt)
		sol = sol->nxt;
	pos->x = sol->pos.x;
	pos->y = sol->pos.y;
	return (pos);
}
