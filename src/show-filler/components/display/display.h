/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:07:36 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/21 02:32:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "show_filler.h"

typedef struct			s_display
{
	t_frame				**frame;
	t_frame				*last_frame;
	int					*win_h;
	int					*win_w;
	t_color				xcolor;
	t_color				ocolor;
	GLuint				tex;
}						t_display;

void			display_draw(void *scene, t_component_data *data, t_rect bounds);

void			display_event(void *scene, t_component_data *data, SDL_Event e);

#endif
