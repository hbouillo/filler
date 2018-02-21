/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 01:03:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/21 05:18:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void			handle_result_event(t_show *show, SDL_UserEvent user_event)
{
	if (!show->result.set)
		show->result = *((t_result *)user_event.data1);
	ft_printf("Result:\n");
	ft_printf("  Player 1: %d\n", show->result.score_1);
	ft_printf("  Player 2: %d\n", show->result.score_2);
}
