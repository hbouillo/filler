/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_commands.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:06:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 16:50:41 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SG_COMMANDS_H
# define SG_COMMANDS_H

# include "sg.h"

void		sg_set_component_boundaries(void *component, t_rect bounds);

void		sg_set_component_position(void *component, t_pos pos);

void		sg_set_component_size(void *component, t_size size);

void		sg_set_component_draw(void *component,
				void (*draw)(void *component, t_component_data *data,
					t_rect bounds));
void		sg_set_component_event(void *component,
				void (*event)(void *component, t_component_data *data,
					SDL_Event e));

void		sg_set_label_color(void *component, t_color color);
void		sg_set_label_text(void *component, void *gstr);

void		sg_set_button_icolor(void *component, t_color color);
void		sg_set_button_ocolor(void *component, t_color color);
void		sg_set_button_hcolor(void *component, t_color color);
void		sg_set_button_pcolor(void *component, t_color color);
void		sg_set_button_edge(void *component, int edge);
void		sg_set_button_radius(void *component, int radius);

#endif
