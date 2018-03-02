/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:15:43 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 01:31:53 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void			handle_scene_event(t_show *show, SDL_UserEvent user_event)
{
	show->gui.active_scene = show->gui.scenes + (int)user_event.data1;
}
