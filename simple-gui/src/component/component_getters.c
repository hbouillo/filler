/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_getters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:37:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/20 20:38:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./component.h"

void		*sg_get_component_data(void *component)
{
	return (((t_component *)component)->data.data);
}
