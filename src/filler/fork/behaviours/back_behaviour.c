/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_behaviour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:06:36 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/06 19:50:05 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fork_champ.h"

t_pos			*push_back(t_fork *fork, t_sol *sol)
{
	t_pos		*pos;

	pos = NULL;
	pos = get_arm_next_pos(sol, fork->arms[BACK_ARM]);
	fork->arms[BACK_ARM].point = *pos;
	return (pos);
}
