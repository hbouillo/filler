/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 00:20:32 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/22 22:35:05 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./button.h"

void		button_event(void *component, t_component_data *data, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONUP)
	{
		if (((t_button *)data->data)->button_action)
			((t_button *)data->data)->button_action(component, data);
	}
}
