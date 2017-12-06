/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:12:36 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/06 19:49:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fork_champ.h"

t_pos			*push_right(t_fork *fork, t_sol *sol)
{
	t_pos		*pos;

	pos = NULL;
	pos = get_arm_next_pos(sol, fork->arms[RIGHT_ARM]);
	fork->arms[RIGHT_ARM].point = *pos;
	return (pos);
}
