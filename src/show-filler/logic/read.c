/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 02:25:24 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/20 02:49:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

static int	parse_player_name(t_show *show, char *line)
{
	char	*name;
	char	*name_tmp;

	if (ft_strlen(line) > 10)
	{
		if ((name_tmp = ft_strrchr(line, '/')))
		{
			name = ft_strdup(name_tmp);
			name_tmp = name;
			while (*name_tmp && *name_tmp != '.')
				name_tmp++;
			*name_tmp = 0;
			if (ft_strlen(name))
			{
				if (line[10] == '1')
					show->reader.p1 = name;
				else
					show->reader.p2 = name;
				return (0);
			}
		}
	}
	name = ft_strdup("Unknown");
	return (1);
}

int			read_input(t_show *show)
{
	char	*line;
	int		ret;
	static int i = 0;

	line = NULL;
	if ((ret = ft_gnl(0, &line)) > 0)
	{
		if (i++ < 50)
			ft_printf("Player 1 is '%s' and Player 2 is '%s' || %s\n", show->reader.p1, show->reader.p1, line);
		if (ft_strnequ(line, "$$$ exec p", 10))
			parse_player_name(show, line);
	}
	if (line)
		free(line);
	return (0);
}
