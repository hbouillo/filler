/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:47:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/08 05:06:58 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_FILLER_H
# define SHOW_FILLER_H

# include <SDL2/SDL.h>
# include <fcntl.h>

# include "libft.h"

# define ERR_SDL 1100, SDL_GetError()
# define ERR_INIT 1000, "Couldn't initialize show-filler"
# define ERR_MALLOC 1001, "Malloc failed"
# define ERR_DATA 1010, "Filler VM sent wrong data"
# define ERR_FILLER 1011, "Filler VM returned an error"
# define ERR_SIGNAL_READ 1020, "Read ready signal registration failed"

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

# define FILLER_EVENT_FRAME 0
# define FILLER_EVENT_ERROR 1

typedef struct		s_map
{
	int				height;
	int				width;
	int				eff_height;
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
	t_map			*map;
	t_frame			*frame;
	char			*p1;
	char			*p2;
}					t_reader;

# define FILLER_SCENES_AMOUNT 1

# define FILLER_SCENE_START 0

typedef struct		s_scenes
{
	void			*active;
	void			*scenes[FILLER_SCENES_AMOUNT];
}					t_scenes;

typedef struct		s_show
{
	SDL_Window		*window;
	SDL_GLContext	context;
	SDL_Rect		max_size;
	t_reader		reader;
	t_scenes		scenes;
	int				run;
}					t_show;

void				error(int errcode, char const *const errmsg, char *errtype,
						int errexit);

int					run_logic(t_show *show);
int					run_event(t_show *show);

unsigned int		get_user_event(void);
void				push_user_event(int code, void *data1, void *data2);

void				handle_new_frame_event(t_show *show, SDL_UserEvent user_event);

#endif
