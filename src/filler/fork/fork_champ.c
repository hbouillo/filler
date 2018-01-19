/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:30:58 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/11 04:46:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_champ.h"

static t_fork			*getfork(t_player *player)
{
	static t_fork	*fork;

	if (!fork)
	{
		if (!(fork = (t_fork *)malloc(sizeof(t_fork))))
			exit(1);
		fork->last_contact_count = 0;
		fork->contacts = 0;
		fork->priority = NO_PRIORITY;
		if (!(fork->arms = (t_arm *)malloc(sizeof(t_arm) * 3)))
			exit(1);
		fork->arms[BACK_ARM] = get_back_arm(player);
		fork->arms[RIGHT_ARM] = get_right_arm(player);
		fork->arms[LEFT_ARM] = get_left_arm(player);
	}
	return (fork);
}

static int			count_contacts(t_map *map, t_player *player)
{
	int				i;
	int				count;

	count = 0;
	i = -1;
	while (++i < map->size.x)
	{
		if (map->data[i] == player->place_char)
			count++;
		if (map->data[(map->size.y - 1) * map->size.x + i] == player->place_char)
			count++;
	}
	i = -1;
	while (++i < map->size.y)
	{
		if (map->data[i * map->size.x] == player->place_char)
			count++;
		if (map->data[i * map->size.x + map->size.x - 1] == player->place_char)
			count++;
	}
	return (count);
}

static t_pos		*nextpos(t_fork *fork, t_sol *sol, t_player *player)
{
	static t_pos	*(*const behaviors[3])(t_fork *fork, t_sol *sol) =
	{ &push_back, &push_right, &push_left };
	int				arm_select;

	if (fork->priority != NO_PRIORITY)
	{
		arm_select = fork->priority;
		if (fork->contacts > 1)
		{
			fork->priority = NO_PRIORITY;
			fork->arms[RIGHT_ARM].dir.x = (player->enemy_spawn.x - fork->arms[RIGHT_ARM].point.x) * 10;
			fork->arms[RIGHT_ARM].dir.y = (player->enemy_spawn.y - fork->arms[RIGHT_ARM].point.y) * 10;
			fork->arms[LEFT_ARM].dir.x = (player->enemy_spawn.x - fork->arms[LEFT_ARM].point.x) * 10;
			fork->arms[LEFT_ARM].dir.y = (player->enemy_spawn.y - fork->arms[LEFT_ARM].point.y) * 10;
			fork->arms[RIGHT_ARM].dir.x = FORK_COS2 * fork->arms[RIGHT_ARM].dir.x - FORK_SIN2 * fork->arms[RIGHT_ARM].dir.y;
			fork->arms[RIGHT_ARM].dir.y = FORK_SIN2 * fork->arms[RIGHT_ARM].dir.x + FORK_COS2 * fork->arms[RIGHT_ARM].dir.y;
			fork->arms[LEFT_ARM].dir.x = FORK_COS2 * fork->arms[LEFT_ARM].dir.x - FORK_SIN2 * fork->arms[LEFT_ARM].dir.y;
			fork->arms[LEFT_ARM].dir.y = FORK_SIN2 * fork->arms[LEFT_ARM].dir.x + FORK_COS2 * fork->arms[LEFT_ARM].dir.y;
		}
	}
	/*if (fork->contacts == 0 && fork->priority == NO_PRIORITY)
		arm_select = BACK_ARM;
	else
	*/if (fork->last_arm == RIGHT_ARM && fork->priority == NO_PRIORITY)
	{
		if (fork->contacts > 0)
			fork->priority = LEFT_ARM;
		arm_select = LEFT_ARM;
		if (fork->contacts <= 1)
		{
			fork->arms[RIGHT_ARM].dir.x = DEV_COS * fork->arms[RIGHT_ARM].dir.x - DEV_SIN * fork->arms[RIGHT_ARM].dir.y;
			fork->arms[RIGHT_ARM].dir.y = DEV_SIN * fork->arms[RIGHT_ARM].dir.x + DEV_COS * fork->arms[RIGHT_ARM].dir.y;
		}
	}
	else if (fork->last_arm == LEFT_ARM && fork->priority == NO_PRIORITY)
	{
		if (fork->contacts > 0)
			fork->priority = RIGHT_ARM;
		arm_select = RIGHT_ARM;
		if (fork->contacts <= 1)
		{
			fork->arms[LEFT_ARM].dir.x = DEV_COS * fork->arms[LEFT_ARM].dir.x + DEV_SIN * fork->arms[LEFT_ARM].dir.y;
			fork->arms[LEFT_ARM].dir.y = -DEV_SIN * fork->arms[LEFT_ARM].dir.x + DEV_COS * fork->arms[LEFT_ARM].dir.y;
		}
	}
	else
		arm_select = RIGHT_ARM;
	fork->last_arm = arm_select;
	return (behaviors[arm_select](fork, sol));
}

t_pos				*fork_nextpos(t_player *player, t_map *map, t_piece *piece)
{
	t_pos			*pos;
	t_fork			*fork;
	t_sol			*sol;
	int				contacts_count;

	fork = getfork(player);
	sol = analyse(player, map, piece);
	pos = NULL;
	contacts_count = count_contacts(map, player);
	if (contacts_count != fork->last_contact_count)
	{
		fork->last_contact_count = contacts_count;
		fork->contacts++;
	}
	while (!pos)
		pos = nextpos(fork, sol, player);
	return (pos);
}
