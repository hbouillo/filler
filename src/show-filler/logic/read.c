/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 02:25:24 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/08 06:58:21 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

int				read_input(t_show *show)
{
	static char	*previous_line;
	char		*line;
	int			ret;

	line = NULL;
	if ((ret = ft_gnl(0, &line)) > 0)
	{
		if (previous_line)
		{
			line = ft_strfjoin(previous_line, line);
			previous_line = NULL;
		}
		ft_printf("%s\n", line);
		parse_line(show, line);
	}
	else if (ret < 0 && ft_strlen(line))
		previous_line = ft_strdup(line);
	if (line)
		free(line);
	return (0);
}
