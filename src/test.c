/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:52:48 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/30 20:50:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int		main(void)
{
	char *line;

	int fd = open("test.out.2.txt", O_RDWR | O_CREAT);
	while (ft_gnl(0, &line))
	{
		ft_putendl_fd(line, fd);
	}
	close(fd);
	return (0);
}
