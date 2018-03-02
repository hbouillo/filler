/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:27:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:24:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SG_H
# define P_SG_H

# include "sg.h"

typedef struct				s_component
{
	void					*scene;
	int						hide;
	t_rect					bounds;
	void					(*draw)(void *component, t_component_data *data,
								t_rect bounds);
	void					(*event)(void *component, t_component_data *data,
								SDL_Event e);
	t_component_data		data;
}							t_component;

typedef struct				s_shared
{
	int						init;
	int						window_w;
	int						last_window_w;
	int						window_h;
	int						last_window_h;
	t_pos					mouse_pos;
	int						mouse_init;
}							t_shared;

typedef struct				s_glyph
{
	char					*buffer;
	unsigned int			rows;
	unsigned int			width;
	long					hori_bearing_x;
	long					hori_bearing_y;
	long					height;
	long					advance_x;
	long					advance_y;
}							t_glyph;

typedef struct				s_gstr
{
	t_glyph					*glyphs;
	t_size					size;
}							t_gstr;

typedef struct				s_scene
{
	t_llist					*queue;
}							t_scene;

t_shared					*sg_get_shared_data(void);

t_gstr						*sg_get_gstr(void *data);

void						sg_resize_gstr(void *gstr);

void						*sg_queue_component(t_component *component);

void						update_mouse(int x, int y);
void						update_window(int width, int height);

#endif
