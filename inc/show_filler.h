/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:47:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/20 03:31:05 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_FILLER_H
# define SHOW_FILLER_H

# include <SDL2/SDL.h>
# include <fcntl.h>

# include "libft.h"

# define ERR_SDL 1100,SDL_GetError()
# define ERR_INIT 1000,"Couldn't initialize show-filler"
# define ERR_DATA 1010 "FIller VM sent wrong data"

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

typedef struct		s_map
{
	int				height;
	int				width;
	char			*map;
}					t_map;

typedef struct		s_result
{
	int				score_1;
	int				score_2;
}					t_result;

typedef struct		s_frame
{
	int				id;
	t_map			*map;
	struct s_frame	*prev;
	struct s_frame	*next;
}					t_frame;

typedef struct		s_reader
{
	t_result		*result;
	t_map			map;
	t_frame			*frame;
	char			*p1;
	char			*p2;
}					t_reader;

typedef struct		s_show
{
	SDL_Window		*window;
	SDL_Rect		max_size;
	t_reader		reader;
	int				run;
}					t_show;

void			error(int errcode, char const *const errmsg, char *errtype,
					int errexit);

int				run_logic(t_show *show);
int				run_event(t_show *show);
#endif
