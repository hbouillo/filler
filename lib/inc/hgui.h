/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgui.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:25:24 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 05:39:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HGUI_H
# define HGUI_H

# include <OpenGL/gl3.h>
# include <SDL2/SDL.h>
# include <mach-o/dyld.h>

# include "libft.h"
# include "ft2build.h"
# include FT_FREETYPE_H

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

char					*get_resource_path(char const *resource);

# define HGUI_MODE_ACTIVE 0
# define HGUI_MODE_PASSIVE 1

/*
** Main loops of an instance
*/
void					hgui_draw(void *scene);

void					hgui_event(void *scene, SDL_Event e, int mode);

/*
** Creates a component using a float based rectangle (OpenGL coordinate system)
** (OpenGL Viewport is defined on [-1.0;1.0] on both axis)
*/
void					*hgui_create_component(void *scene, GLuint shader_prog);

/*
** The following section contains basic components functions.
*/

void					*hgui_create_button(void *scene);

void					*hgui_create_label(void *scene);

void					hgui_hide_component(void *component);
void					hgui_show_component(void *component);
int						hgui_has_flags(void *component, int flags);
void					hgui_set_flags(void *component, int flags);
void					hgui_unset_flags(void *component, int flags);

/*
**	Utils
*/

t_pos					hgui_posf(float x, float y);
t_pos					hgui_posi(int x, int y);
t_size					hgui_sizef(float w, float h);
t_size					hgui_sizei(int w, int h);
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

void					*hgui_new_gstr(char const *str,
							char const *font_file, int size);
void					hgui_del_gstr(void *gstr_ptr);

void					hgui_draw_gstr(void *gstr, t_color color, t_pos pos);

# include "hgui_commands.h"

#endif
