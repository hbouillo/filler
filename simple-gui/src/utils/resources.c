/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 04:26:42 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:11:36 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sg.h"

char			*get_resource_path(char const *resource)
{
	char		*resource_path;
	char		*tmp;
	uint32_t	size;

	size = 0;
	resource_path = NULL;
	_NSGetExecutablePath(resource_path, &size);
	if (!(resource_path = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	_NSGetExecutablePath(resource_path, &size);
	resource_path[size] = 0;
	tmp = resource_path;
	resource_path = realpath(resource_path, NULL);
	free(tmp);
	*(ft_strrchr(resource_path, '/') + 1) = 0;
	tmp = resource_path;
	resource_path = ft_strjoin(resource_path, "res/");
	free(tmp);
	tmp = resource_path;
	resource_path = ft_strjoin(resource_path, resource);
	free(tmp);
	return (resource_path);
}
