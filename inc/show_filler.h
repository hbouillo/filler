/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:47:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/05 05:44:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_FILLER_H
# define SHOW_FILLER_H

# include <SDL2/SDL.h>
# include <fcntl.h>
# include <time.h>
# include <pthread.h>

# include "libft.h"
# include "sg.h"
# include "sg_commands.h"

# define FRAME_PER_SECOND 60
# define TICKS_PER_SECOND 60

# define ERR_SDL 1100, SDL_GetError()
# define ERR_INIT 1000, "Couldn't initialize show-filler"
# define ERR_MALLOC 1001, "Malloc failed"
# define ERR_DATA 1010, "Filler VM sent wrong data"
# define ERR_FILLER 1011, "Filler VM returned an error"

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

# define FILLER_EVENT_ERROR -1
# define FILLER_EVENT_FRAME 0
# define FILLER_EVENT_PLAYERS 1
# define FILLER_EVENT_RESULT 2
# define FILLER_EVENT_SCENE 3

# define FILLER_FONT "fonts/TheLightFont.ttf"
# define FILLER_TOP_FONT_SIZE 30

typedef struct timespec	t_time;

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
	t_result		score;
	t_map			*map;
	struct s_frame	*prev;
	struct s_frame	*next;
}					t_frame;

typedef struct		s_reader
{
	int				end;
	t_map			*map;
	char			*p1;
	char			*p2;
}					t_reader;

# define FILLER_SCENES_AMOUNT 2

# define FILLER_SCENE_MAIN 0
# define FILLER_SCENE_END 1

typedef struct		s_main_scene
{
	void			*ptr;
	void			*top_frame;
	void			*p1_label;
	void			*p2_label;
	void			*vs_label;
	void			*madeby_label;
	void			*p1_score_label;
	void			*p2_score_label;
	void			*main_frame;
	void			*display_frame;
	void			*pause_button;
	void			*next_button;
	void			*prev_button;
	void			*end_button;
	void			*begin_button;
	void			*faster_button;
	void			*slower_button;
}					t_main_scene;

typedef struct		s_end_scene
{
	void			*ptr;
	void			*heckyeah;
	void			*msg;
	void			*vs;
	void			*score_1;
	void			*score_2;
	void			*popup;
	void			*background;
}					t_end_scene;

typedef union		u_scene
{
	void			*ptr;
	t_main_scene	main;
	t_end_scene		end;
}					t_scene;

typedef struct		s_color_set
{
	t_color			background;
	t_color			main_text;
	t_color			display_edge;
	t_color			display_grid;
	t_color			display_o;
	t_color			display_x;
	t_color			button_hover;
	t_color			button_pressed;
}					t_color_set;

typedef struct		s_gui
{
	t_color_set		*colors;
	t_scene			*active_scene;
	t_scene			scenes[FILLER_SCENES_AMOUNT];
	int				pause;
}					t_gui;

typedef struct		s_show
{
	pthread_mutex_t	run_mutex;
	SDL_Window		*window;
	SDL_GLContext	context;
	SDL_Rect		max_size;
	int				win_h;
	int				win_w;
	t_gui			gui;
	char			*players[2];
	t_frame			*frames;
	int				end;
	int				run;
	int				tps;
}					t_show;

void				error(int errcode, char const *const errmsg, char *errtype,
						int errexit);

void				init_gui(t_show *show);
void				uninit_gui(t_show *show);

pthread_t			start_read(t_show *show);

int					run_logic(t_show *show);
int					run_event(t_show *show);
void				run_gui(t_show *show);

void				frame_update(t_show *show);

unsigned int		get_user_event(void);
void				push_user_event(int code, void *data1, void *data2);

void				*show_create_display(void *scene, t_show *show);
void				show_set_display_xcolor(void *component, t_color color);
void				show_set_display_ocolor(void *component, t_color color);
void				show_set_display_ecolor(void *component, t_color color);
void				show_set_display_gcolor(void *component, t_color color);
void				show_set_display_edge(void *component, int edge);

void				set_color_set(t_show *show, int set);

#endif
