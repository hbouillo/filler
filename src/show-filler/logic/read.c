/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 02:25:24 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 00:03:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

static void			send_events(t_reader *reader)
{
	if (reader->map && reader->map->eff_height == reader->map->height)
	{
		push_user_event(FILLER_EVENT_FRAME, reader->map, NULL);
		reader->map = NULL;
	}
	if (reader->p1 || reader->p2)
	{
		push_user_event(FILLER_EVENT_PLAYERS, reader->p1, reader->p2);
		reader->p1 = NULL;
		reader->p2 = NULL;
	}
	if (reader->end)
		push_user_event(FILLER_EVENT_RESULT, NULL, NULL);
}

static int			read_input(void)
{
	static t_reader	reader;
	static char		*previous_line;
	char			*line;
	int				ret;

	line = NULL;
	if ((ret = ft_gnl(0, &line)) > 0)
	{
		if (previous_line)
		{
			line = ft_strfjoin(previous_line, line);
			previous_line = NULL;
		}
		parse_line(&reader, line);
		send_events(&reader);
	}
	else if (ret < 0 && ft_strlen(line))
		if (!(previous_line = ft_strdup(line)))
			error(ERR_MALLOC, ERR_CRITICAL);
	if (line)
		free(line);
	return (0);
}

static void			*run_read(void *arg)
{
	t_show			*show;
	int				run;

	run = 1;
	show = (t_show *)arg;
	while (run)
	{
		pthread_mutex_lock(&(show->run_mutex));
		if (!show->run)
			run = 0;
		pthread_mutex_unlock(&(show->run_mutex));
		read_input();
	}
	return (NULL);
}

pthread_t			start_read(t_show *show)
{
	pthread_t		read_thread;

	pthread_create(&read_thread, NULL, &run_read, show);
	return (read_thread);
}
