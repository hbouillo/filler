/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:47:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/19 04:47:01 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_FILLER_H
# define SHOW_FILLER_H

# include <SDL2/SDL.h>
# include "libft.h"

# define ERR_SDL 1100,SDL_GetError()
# define ERR_INIT 1000,"Couldn't initialize show-filler."

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

typedef struct		s_show
{
	SDL_Window		*window;
	SDL_Rect		max_size;
	int				run;
}					t_show;

void			error(int errcode, char const *const errmsg, char *errtype,
					int errexit);

#endif
