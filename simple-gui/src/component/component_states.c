/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 03:56:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 16:55:31 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./component.h"

void				sg_hide_component(void *component)
{
	((t_component *)component)->hide = 1;
}

void				sg_show_component(void *component)
{
	((t_component *)component)->hide = 0;
}

int					sg_has_flags(void *component, int flags)
{
	return (((t_component *)component)->data.states & flags);
}

void				sg_set_flags(void *component, int flags)
{
	((t_component *)component)->data.states |= flags;
}

void				sg_unset_flags(void *component, int flags)
{
	((t_component *)component)->data.states &= ~flags;
}
