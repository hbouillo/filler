/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:47:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/20 06:08:06 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_FILLER_H
# define SHOW_FILLER_H

# include <SDL2/SDL.h>
# include <fcntl.h>
# include <time.h>

# include "libft.h"
# include "sg.h"

# define FRAME_PER_SECOND 60
# define TICKS_PER_SECOND 60

# define ERR_SDL 1100, SDL_GetError()
# define ERR_INIT 1000, "Couldn't initialize show-filler"
# define ERR_MALLOC 1001, "Malloc failed"
# define ERR_DATA 1010, "Filler VM sent wrong data"
# define ERR_FILLER 1011, "Filler VM returned an error"
# define ERR_SIGNAL_READ 1020, "Read ready signal registration failed"

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

# define FILLER_EVENT_ERROR -1
# define FILLER_EVENT_FRAME 0
# define FILLER_EVENT_PLAYERS 1
# define FILLER_EVENT_RESULT 2

# define FILLER_COLOR_BACKGROUND 0.9, 0.9, 0.9, 1.0

# define FILLER_COLOR_TEXT 0.3, 0.3, 0.3, 1.0

# define FILLER_FONT "fonts/TheLightFont.ttf"
# define FILLER_TOP_FONT_SIZE 30

typedef struct	timespec	t_time;

typedef struct		s_map
{
	int				height;
	int				width;
	int				eff_height;
	char			*map;
}					t_map;

typedef struct		s_result
{
	int				set;
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
	t_result		result;
	t_map			*map;
	char			*p1;
	char			*p2;
}					t_reader;

# define FILLER_SCENES_AMOUNT 1

# define FILLER_SCENE_MAIN 0

typedef struct		s_main_scene
{
	void			*ptr;
	void			*p1_label;
	void			*p2_label;
	void			*vs_label;
	void			*top_frame;
	void			*main_frame;
}					t_main_scene;

typedef union		u_scene
{
	void			*ptr;
	t_main_scene	main;
}					t_scene;

typedef struct		s_gui
{
	t_scene			*active_scene;
	t_scene			scenes[FILLER_SCENES_AMOUNT];
}					t_gui;

typedef struct		s_show
{
	SDL_Window		*window;
	SDL_GLContext	context;
	SDL_Rect		max_size;
	int				win_h;
	int				win_w;
	t_gui			gui;
	char			*players[2];
	t_frame			*frames;
	t_result		result;
	int				run;
}					t_show;

void				error(int errcode, char const *const errmsg, char *errtype,
						int errexit);

void				init_gui(t_show *show);

int					run_logic(t_show *show);
int					run_event(t_show *show);
void				run_gui(t_show *show);

unsigned int		get_user_event(void);
void				push_user_event(int code, void *data1, void *data2);

void				handle_new_frame_event(t_show *show, SDL_UserEvent user_event);
void				handle_players_event(t_show *show, SDL_UserEvent user_event);
void				handle_result_event(t_show *show, SDL_UserEvent user_event);

void				init_main_scene(t_show *show, t_main_scene *main);

#endif
