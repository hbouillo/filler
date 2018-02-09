/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgui.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:25:24 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/09 03:06:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HGUI_H
# define HGUI_H

# include "libft.h"
# include "ft2build.h"
# include FT_FREETYPE_H
# include <OpenGL/gl3.h>
# include <SDL2/SDL.h>
# include "hgui_commands.h"

typedef struct			s_color
{
	float				r;
	float				g;
	float				b;
	float				a;
}						t_color;

typedef struct			s_size
{
	float				w;
	float				h;
}						t_size;

typedef struct			s_pos
{
	float				x;
	float				y;
}						t_pos;

typedef struct			s_rect
{
	float				x;
	float				y;
	float				w;
	float				h;
}						t_rect;

typedef struct			s_font
{
	FT_Face				fontface;
	int					size;
	t_color				color;
}						t_font;

# define STATE_COMPONENT_PRESSED 0x01
# define STATE_COMPONENT_HOVERED 0x02

# define STATE_COMPONENT_LOCK_TOP 0x0100
# define STATE_COMPONENT_LOCK_BOTTOM 0x0200
# define STATE_COMPONENT_LOCK_LEFT 0x0400
# define STATE_COMPONENT_LOCK_RIGHT 0x0800

# define STATE_COMPONENT_LOCK_WIDTH 0x1000
# define STATE_COMPONENT_LOCK_HEIGHT 0x2000
# define STATE_COMPONENT_LOCK_SIZE 0x3000

# define HGUI_ALIGN_TOP 0x010000
# define HGUI_ALIGN_BOTTOM 0x020000
# define HGUI_ALIGN_LEFT 0x040000
# define HGUI_ALIGN_RIGHT 0x080000

typedef struct			s_component_data
{
	int					index;
	int					states;
	int					full_draw;
	GLuint				vao;
	GLuint				*vbos;
	GLuint				shader_prog;
	void				*data;
}						t_component_data;

/*
** Init an instance of the library components management system
*/
void					*hgui_new_scene(SDL_Window *window);

/*
** Destroys an instance of the library components management system
*/
void					hgui_destroy_scene(void *scene);

# define HGUI_MODE_ACTIVE 0
# define HGUI_MODE_PASSIVE 1

/*
** Main loops of an instance
*/
void					hgui_draw(void *scene);

void					hgui_event(void *scene, SDL_Event e, int mode);

/*
** Returns a pointer to a new to-be-instanced component manager
*/
void					*hgui_init_component_manager(void *data,
							void (*draw)(void *scene, t_component_data *data,
								t_rect boundsf),
							void (*event)(void *scene, t_component_data *data,
								SDL_Event e));

/*
** Creates a component using a float based rectangle (OpenGL coordinate system)
** (OpenGL Viewport is defined on [-1.0;1.0] on both axis)
*/
int						hgui_create_component(void *scene, void *cmanager,
							t_rect bounds, GLuint shader_prog);

/*
** The following section contains basic components functions.
*/

typedef struct			s_button
{
	t_font				font;
	char				*label;
	void				(*button_action)(void *scene, t_component_data *data);
	t_color				icolor;
	t_color				ocolor;
	t_color				hcolor;
	t_color				pcolor;
	int					radius;
	int					edge;
}						t_button;

int						hgui_create_button(void *scene, t_rect bounds, t_button button);

typedef struct			s_label
{
	t_font				font;
	char				*label;
}						t_label;

int						hgui_create_label(void *scene, t_rect bounds, t_label label);

void					hgui_hide_component(void *scene, int index);
void					hgui_show_component(void *scene, int index);
int						hgui_has_flags(void *scene, int index, int flags);
void					hgui_set_flags(void *scene, int index, int flags);
void					hgui_unset_flags(void *scene, int index, int flags);

/*
**	Utils
*/

t_pos					hgui_posf(float x, float y);
t_pos					hgui_posi(void *scene, int x, int y);
t_size					hgui_sizef(float w, float h);
t_size					hgui_sizei(void *scene, int w, int h);
t_rect					hgui_rectf(float x, float y, float w, float h);
t_rect					hgui_rect(t_pos pos, t_size size);

void					hgui_align_bounds(t_rect *bounds, int alignement);

void					hgui_rect_to_vec2buf(t_rect rect, float *buf);
int						hgui_is_in_rect(t_rect rect, t_pos pos);

t_color					hgui_colorf(float r, float g, float b, float a);
t_color					hgui_colori(int r, int g, int b, int a);

void					hgui_uniform_color(GLuint uniform, t_color color);
void					hgui_uniform_rect(GLuint uniform, t_rect bounds);

GLuint					get_shader_prog(char const *fs_file, char const *vs_file);

t_font					hgui_create_font(void *scene, char const *file, int size, t_color color);
t_size					hgui_str_font_size(void *scene, t_font font, char const *str);

void					hgui_draw_string(void *scene, char const *str, t_font font, t_pos pos);

#endif
