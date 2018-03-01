/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choke_champ.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:02:20 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:27:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOKE_CHAMP_H
# define CHOKE_CHAMP_H

# include "filler.h"

# define GRADE_PROXIMITY 1
# define GRADE_BREAK 100

t_pos				*default_pos(t_sol *sol, t_map *map, t_player *player);

#endif
