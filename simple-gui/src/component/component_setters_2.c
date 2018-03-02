/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_setters_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 05:13:41 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:36:41 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./component.h"

void		sg_set_component_data(void *component, void *data)
{
	((t_component *)component)->data.data = data;
}

void		sg_redraw_component(void *component)
{
	((t_component *)component)->data.full_draw = 1;
}
