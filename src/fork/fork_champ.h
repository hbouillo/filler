/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_champ.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:28:29 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/05 20:36:00 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_CHAMP_H
# define FORK_CHAMP_H

# define FORK_COS 0.70710678118
# define FORK_SIN 0.70710678118

# define FORK_COS_DEV 0.98480775301
# define FORK_SIN_DEV -0.17364817766

# define FORK_RIGHT 0
# define FORK_BACK -1
# define FORK_LEFT 1

typedef struct		s_fork
{
	char			status;
	t_arm			arm_back;
	t_arm			arm_r;
	t_arm			arm_l;
}					t_fork;

#endif
