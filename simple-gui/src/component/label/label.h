/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 04:04:20 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:23:06 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

# include "../component.h"

typedef struct			s_label
{
	void				*gstr;
	t_color				color;
}						t_label;

void					label_draw(void *scene, t_component_data *data,
							t_rect bounds);

void					label_event(void *scene, t_component_data *data,
							SDL_Event e);

#endif
