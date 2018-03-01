/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:28:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:16:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "show_filler.h"

void		handle_new_frame_event(t_show *show, SDL_UserEvent user_event);
void		handle_players_event(t_show *show, SDL_UserEvent user_event);
void		handle_result_event(t_show *show, SDL_UserEvent user_event);
void		handle_key_event(t_show *show, SDL_KeyboardEvent event);

#endif
