/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:34:21 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:22:41 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "../component.h"

typedef struct			s_button
{
	void				*gstr;
	t_color				font_color;
	void				(*button_action)(void *component,
							t_component_data *data);
	t_color				icolor;
	t_color				ocolor;
	t_color				hcolor;
	t_color				pcolor;
	int					radius;
	int					edge;
}						t_button;

void					button_draw(void *scene, t_component_data *data,
							t_rect bounds);

void					button_event(void *scene, t_component_data *data,
							SDL_Event e);

#endif
