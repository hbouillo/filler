/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 06:54:18 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/27 23:53:04 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

static void		parse_player_name(t_reader *reader, char *line)
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
					reader->p1 = name;
				else
					reader->p2 = name;
					return ;
			}
			free(name);
		}
	}
	name = ft_strdup("Unknown");
	error(ERR_DATA, ERR_CRITICAL);
}

static void		parse_map_data(t_reader *reader, char *line)
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
	ft_chartabfree(split);
	if (width <= 0 || height <= 0 ||
		(usual_height != -1 && usual_height != height) ||
		(usual_width != -1 && usual_width != width))
		error(ERR_DATA, ERR_CRITICAL);
	if (reader->map ||
		!(reader->map = (t_map *)ft_memalloc(sizeof(t_map))) ||
		!(reader->map->map =
		(char *)ft_memalloc(sizeof(char) * height * width)))
		error(ERR_MALLOC, ERR_CRITICAL);
	reader->map->height = height;
	reader->map->width = width;
	usual_height = height;
	usual_width = width;
}

static void		parse_map_line(t_reader *reader, char *line)
{
	int			line_number;
	int			width;

	line_number = ft_atoi(line);
	if (line_number > reader->map->height)
		error(ERR_DATA, ERR_CRITICAL);
	line += 4;
	width = -1;
	while (++width < reader->map->width)
		reader->map->map[reader->map->width * reader->map->eff_height + width] =
			line[width];
	reader->map->eff_height++;
}

static int		is_map_line(t_reader *reader, char *line)
{
	char		*line_ptr;

	if (!reader->map || ft_strlen(line) != (size_t)(4 + reader->map->width))
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

void			parse_line(t_reader *reader, char *line)
{
	if (ft_strnequ(line, "$$$ exec p", 10))
		parse_player_name(reader, line);
	else if (ft_strnequ(line, "An error occured", 16))
		push_user_event(FILLER_EVENT_ERROR, NULL, NULL);
	else if (ft_strnequ(line, "Plateau ", 8))
		parse_map_data(reader, line);
	else if (is_map_line(reader, line))
		parse_map_line(reader, line);
	else if (ft_strnequ(line, "== O fin: ", 10))
	{
		reader->result.score_1 = ft_atoi(ft_strrchr(line, ' '));
		reader->result.set++;
	}
	else if (ft_strnequ(line, "== X fin: ", 10))
	{
		reader->result.score_2 = ft_atoi(ft_strrchr(line, ' '));
		reader->result.set++;
	}
}
