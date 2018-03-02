/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 05:57:46 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 16:55:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./label.h"

void			sg_set_label_color(void *component, t_color color)
{
	t_label		*label;

	label = (t_label *)((t_component *)component)->data.data;
	label->color = color;
}

void			sg_set_label_text(void *component_ptr, void *gstr)
{
	t_component	*component;
	t_label		*label;

	component = (t_component *)component_ptr;
	label = (t_label *)component->data.data;
	if (label->gstr)
		sg_del_gstr(label->gstr);
	label->gstr = gstr;
	component->bounds.w = sg_get_gstr(label->gstr)->size.w;
	component->bounds.h = sg_get_gstr(label->gstr)->size.h;
}
