/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:39:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:37:36 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./label.h"

void			label_draw(void *component, t_component_data *data,
					t_rect bounds)
{
	t_pos		text_pos;
	t_label		*label;

	component = NULL;
	label = ((t_label *)data->data);
	if (!label->gstr)
		return ;
	text_pos.x = bounds.x;
	text_pos.y = bounds.y;
	sg_draw_gstr(label->gstr, label->color, text_pos);
}
