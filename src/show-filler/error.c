/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:44:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:45:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

void				error(int errcode, char const *const errmsg, char *errtype,
						int errexit)
{
	printf("%s (ERRCODE=%d, ERRMSG=\"%s\")\n", errtype, errcode, errmsg);
	if (errexit)
	{
		SDL_Quit();
		exit(1);
	}
}
