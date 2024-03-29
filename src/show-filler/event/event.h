/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:28:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 01:17:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "show_filler.h"

void		handle_new_frame_event(t_show *show, SDL_UserEvent user_event);
void		handle_players_event(t_show *show, SDL_UserEvent user_event);
void		handle_result_event(t_show *show, SDL_UserEvent user_event);
void		handle_key_event(t_show *show, SDL_KeyboardEvent event);
void		handle_scene_event(t_show *show, SDL_UserEvent event);

#endif
