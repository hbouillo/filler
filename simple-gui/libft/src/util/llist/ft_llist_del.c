/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 01:30:09 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/14 01:44:32 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_llist_del(t_llist **head, void (*del_data)(void *))
{
	t_llist			*tmp;

	while (*head)
	{
		del_data((*head)->data);
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
