/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 01:03:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 23:59:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void			handle_result_event(t_show *show, SDL_UserEvent user_event)
{
	show->end = 1;
	ft_printf("Match has ended...\n");
}
