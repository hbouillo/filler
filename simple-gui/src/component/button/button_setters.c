/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 06:00:05 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/22 21:19:44 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./button.h"

void			sg_set_button_icolor(void *component, t_color color)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->icolor = color;
}

void			sg_set_button_ocolor(void *component, t_color color)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->ocolor = color;
}

void			sg_set_button_hcolor(void *component, t_color color)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->hcolor = color;
}

void			sg_set_button_pcolor(void *component, t_color color)
{
	t_button	*button;

	button = (t_button *)((t_component *)component)->data.data;
	button->pcolor = color;
}

void			sg_set_button_text(void *component_ptr, void *gstr)
{
	t_component	*component;
	t_button	*button;

	component = (t_component *)component_ptr;
	button = (t_button *)component->data.data;
	if (button->gstr)
		sg_del_gstr(button->gstr);
	button->gstr = gstr;
}
