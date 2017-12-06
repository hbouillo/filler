/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_behaviour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:12:36 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/06 19:50:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fork_champ.h"

t_pos			*push_left(t_fork *fork, t_sol *sol)
{
	t_pos		*pos;

	pos = NULL;
	pos = get_arm_next_pos(sol, fork->arms[LEFT_ARM]);
	fork->arms[LEFT_ARM].point = *pos;
	return (pos);
}
