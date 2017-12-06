/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_champ.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:28:29 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/06 20:07:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_CHAMP_H
# define FORK_CHAMP_H

# define FORK_COS COS50
# define FORK_SIN SIN50
# define FORK_COS2 COS20
# define FORK_SIN2 SIN20

# define DEV_COS COS3
# define DEV_SIN SIN3

# define COS50 0.64278760968
# define SIN50 0.76604444311
# define COS60 0.5
# define SIN60 0.86602540378
# define COS45 0.70710678118
# define SIN45 0.70710678118
# define COS70 0.34202014332
# define SIN70 0.93969262078
# define COS30 0.86602540378
# define SIN30 0.5
# define COS20 0.93969262078
# define SIN20 0.34202014332
# define COS90 0
# define SIN90 1
# define COS3 0.99862953475
# define SIN3 0.05233595624

# define FORK_COS_DEV 0.98480775301
# define FORK_SIN_DEV -0.17364817766

# define NO_PRIORITY -1
# define BACK_ARM 0
# define RIGHT_ARM 1
# define LEFT_ARM 2

#include "filler.h"

typedef struct		s_fork
{
	int				last_contact_count;
	int				contacts;
	int				last_arm;
	int				priority;
	t_arm			*arms;
}					t_fork;

t_arm			get_right_arm(t_player *player);
t_arm			get_left_arm(t_player *player);
t_arm			get_back_arm(t_player *player);

t_pos			*push_back(t_fork *fork, t_sol *sol);
t_pos			*push_right(t_fork *fork, t_sol *sol);
t_pos			*push_left(t_fork *fork, t_sol *sol);

#endif
