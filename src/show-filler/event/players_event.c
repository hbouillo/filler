/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:37:26 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 01:30:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

void			handle_players_event(t_show *show, SDL_UserEvent user_event)
{
	if (!show->players[0] && user_event.data1)
		show->players[0] = user_event.data1;
	if (!show->players[1] && user_event.data2)
		show->players[1] = user_event.data2;
}
