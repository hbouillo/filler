/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:18:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 04:49:35 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "show_filler.h"
# include "hgui.h"

# define FILLER_SCENES_AMOUNT 1

# define FILLER_SCENE_MAIN 0

typedef struct		s_main_scene
{
	void			*ptr;
	int				label;
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

t_gui				*get_gui();

void				init_main_scene(SDL_Window *window, t_main_scene *main);

#endif
