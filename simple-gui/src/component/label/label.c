/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:06:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:20:13 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./label.h"
#include "sg_commands.h"

static t_label	*default_label_data(void)
{
	t_label		*label_data;

	if (!(label_data = (t_label *)ft_memalloc(sizeof(t_label))))
		return (NULL);
	label_data->color = sg_colorf(1.0, 1.0, 1.0, 1.0);
	return (label_data);
}

void			*sg_create_label(void *scene)
{
	void		*label_ptr;

	if (!(label_ptr = sg_create_component(scene, 0)))
		return (NULL);
	sg_set_component_draw(label_ptr, &label_draw);
	sg_set_component_event(label_ptr, &label_event);
	if (!(((t_component *)label_ptr)->data.data = default_label_data()))
		return (NULL);
	sg_set_flags(label_ptr, SG_LOCK_WIDTH
								| SG_LOCK_HEIGHT);
	return (label_ptr);
}
