/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:32:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 02:57:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "show_filler.h"

void					init_main_scene(t_show *show, t_main_scene *main);
void					init_end_scene(t_show *show, t_end_scene *main);

void					main_update_colors(t_show *show, t_main_scene *main);
void					end_update_colors(t_show *show, t_end_scene *end);

#endif
