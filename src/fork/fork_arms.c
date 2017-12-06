/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_arms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:40:14 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/06 19:18:16 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_champ.h"

t_arm			get_right_arm(t_player *player)
{
	t_arm		right_arm;

	right_arm.point.x = player->my_spawn.x;
	right_arm.point.y = player->my_spawn.y;
	right_arm.dir.x = (player->enemy_spawn.x - right_arm.point.x) * 10;
	right_arm.dir.y = (player->enemy_spawn.y - right_arm.point.y) * 10;
	right_arm.dir.x = FORK_COS * right_arm.dir.x - FORK_SIN * right_arm.dir.y;
	right_arm.dir.y = FORK_SIN * right_arm.dir.x + FORK_COS * right_arm.dir.y;
	return (right_arm);
}

t_arm			get_left_arm(t_player *player)
{
	t_arm		left_arm;

	left_arm.point.x = player->my_spawn.x;
	left_arm.point.y = player->my_spawn.y;
	left_arm.dir.x = (player->enemy_spawn.x - left_arm.point.x) * 10;
	left_arm.dir.y = (player->enemy_spawn.y - left_arm.point.y) * 10;
	left_arm.dir.x = FORK_COS * left_arm.dir.x + FORK_SIN * left_arm.dir.y;
	left_arm.dir.y = -FORK_SIN * left_arm.dir.x + FORK_COS * left_arm.dir.y;
	return (left_arm);
}

t_arm			get_back_arm(t_player *player)
{
	t_arm		back_arm;

	back_arm.point.x = player->my_spawn.x;
	back_arm.point.y = player->my_spawn.y;
	back_arm.dir.x = -(player->enemy_spawn.x - back_arm.point.x) * 10;
	back_arm.dir.y = -(player->enemy_spawn.y - back_arm.point.y) * 10;;
	return (back_arm);
}
