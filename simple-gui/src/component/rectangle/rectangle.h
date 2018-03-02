/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 04:22:16 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:23:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_H
# define RECTANGLE_H

# include "../component.h"

typedef struct			s_rectangle
{
	t_color				icolor;
	t_color				ocolor;
	int					radius;
	int					edge;
}						t_rectangle;

void					rectangle_draw(void *scene, t_component_data *data,
							t_rect bounds);

void					rectangle_event(void *scene, t_component_data *data,
							SDL_Event e);

#endif
