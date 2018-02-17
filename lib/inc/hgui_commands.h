/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgui_commands.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:06:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 06:07:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HGUI_COMMANDS_H
# define HGUI_COMMANDS_H

# include "hgui.h"

void		hgui_set_component_boundaries(void *component, t_rect bounds);

void		hgui_set_component_position(void *component, t_pos pos);

void		hgui_set_component_size(void *component, t_size size);

void		hgui_set_component_draw(void *component,
				void (*draw)(void *component, t_component_data *data,
					t_rect bounds));
void		hgui_set_component_event(void *component,
				void (*event)(void *component, t_component_data *data,
					SDL_Event e));

void		hgui_set_label_color(void *component, t_color color);
void		hgui_set_label_text(void *component, void *gstr);

void		hgui_set_button_icolor(void *component, t_color color);
void		hgui_set_button_ocolor(void *component, t_color color);
void		hgui_set_button_hcolor(void *component, t_color color);
void		hgui_set_button_pcolor(void *component, t_color color);
void		hgui_set_button_edge(void *component, int edge);
void		hgui_set_button_radius(void *component, int radius);

#endif
