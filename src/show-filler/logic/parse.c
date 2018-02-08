/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 06:54:18 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/08 06:57:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

static void		parse_player_name(t_show *show, char *line)
{
	char		*name;
	char		*name_tmp;

	if (ft_strlen(line) > 10)
	{
		if ((name_tmp = ft_strrchr(line, '/')))
		{
			name = ft_strdup(name_tmp + 1);
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
					return ;
			}
			free(name);
		}
	}
	name = ft_strdup("Unknown");
	error(ERR_DATA, ERR_CRITICAL);
}

static void		parse_map_data(t_show *show, char *line)
{
	static int	usual_height = -1;
	static int	usual_width = -1;
	int			height;
	int			width;
	char		**split;

	split = ft_strsplit(line, ' ');
	if (ft_chartablen(split) != 3)
		error(ERR_DATA, ERR_CRITICAL);
	height = ft_atoi(split[1]);
	width = ft_atoi(split[2]);
	if (width <= 0 || height <= 0 ||
		(usual_height != -1 && usual_height != height) ||
		(usual_width != -1 && usual_width != width))
		error(ERR_DATA, ERR_CRITICAL);
	if (show->reader.map ||
		!(show->reader.map = (t_map *)ft_memalloc(sizeof(t_map))) ||
		!(show->reader.map->map =
		(char *)ft_memalloc(sizeof(char) * height * width)))
		error(ERR_MALLOC, ERR_CRITICAL);
	show->reader.map->height = height;
	show->reader.map->width = width;
	usual_height = height;
	usual_width = width;
}

static void		parse_map_line(t_show *show, char *line)
{
	int			line_number;
	int			width;

	line_number = ft_atoi(line);
	if (line_number > show->reader.map->height)
		error(ERR_DATA, ERR_CRITICAL);
	line += 4;
	width = -1;
	while (++width < show->reader.map->width)
		show->reader.map->map[show->reader.map->width * show->reader.map->eff_height + width] =
			line[width];
	show->reader.map->eff_height++;
}

static int		is_map_line(t_show *show, char *line)
{
	char		*line_ptr;

	if (!show->reader.map || ft_strlen(line) != 4 + show->reader.map->width)
			return (0);
	line_ptr = line - 1;
	while (++line_ptr - line < 3)
		if (!ft_isdigit(*(line_ptr)))
			return (0);
	if (*line_ptr != ' ')
		return (0);
	while (*(++line_ptr))
		if (ft_toupper(*line_ptr) != 'O' && ft_toupper(*line_ptr) != 'X' &&
			*line_ptr != '.')
			return (0);
	return (1);
}

void			parse_line(t_show *show, char *line)
{
	if (ft_strnequ(line, "$$$ exec p", 10))
		parse_player_name(show, line);
	else if (ft_strnequ(line, "An error occured", 16))
		push_user_event(FILLER_EVENT_ERROR, NULL, NULL);
	else if (ft_strnequ(line, "Plateau ", 8))
		parse_map_data(show, line);
	else if (is_map_line(show, line))
		parse_map_line(show, line);
	if (show->reader.map &&
		show->reader.map->eff_height == show->reader.map->height)
	{
		push_user_event(FILLER_EVENT_FRAME, show->reader.map, NULL);
		show->reader.map = NULL;
	}
}
