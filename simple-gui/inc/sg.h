/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:25:24 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 02:47:45 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SG_H
# define SG_H

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

# define SG_PRESSED 0x01
# define SG_HOVERED 0x02

# define SG_LOCK_TOP 0x0100
# define SG_LOCK_BOTTOM 0x0200
# define SG_LOCK_LEFT 0x0400
# define SG_LOCK_RIGHT 0x0800

# define SG_LOCK_MID_X 0x1000
# define SG_LOCK_MID_Y 0x2000
# define SG_LOCK_MID 0x3000

# define SG_LOCK_WIDTH 0x4000
# define SG_LOCK_HEIGHT 0x8000
# define SG_LOCK_SIZE 0xC000

# define SG_ALIGN_TOP 0x010000
# define SG_ALIGN_BOTTOM 0x020000
# define SG_ALIGN_LEFT 0x040000
# define SG_ALIGN_RIGHT 0x080000

typedef struct			s_component_data
{
	int					index;
	int					states;
	int					full_draw;
	GLuint				vao;
	int					vbo_count;
	GLuint				*vbos;
	GLuint				shader_prog;
	void				*data;
}						t_component_data;

/*
** Init an instance of the library components management system
*/
void					*sg_new_scene(SDL_Window *window);

/*
** Destroys an instance of the library components management system
*/
void					sg_destroy_scene(void *scene);

char					*get_resource_path(char const *resource);

# define SG_MODE_ACTIVE 0
# define SG_MODE_PASSIVE 1

/*
** Main loops of an instance
*/
void					sg_draw(void *scene);

void					sg_event(void *scene, SDL_Event e, int mode);

/*
** Creates a component using a float based rectangle (OpenGL coordinate system)
** (OpenGL Viewport is defined on [-1.0;1.0] on both axis)
*/
void					*sg_create_component(void *scene, GLuint shader_prog);

/*
** The following section contains basic components functions.
*/

void					*sg_create_rectangle(void *scene);

void					*sg_create_button(void *scene);

void					*sg_create_label(void *scene);

void					sg_hide_component(void *component);
void					sg_show_component(void *component);
int						sg_has_flags(void *component, int flags);
void					sg_set_flags(void *component, int flags);
void					sg_unset_flags(void *component, int flags);

/*
**	Utils
*/

t_pos					sg_posf(float x, float y);
t_pos					sg_posf_pad(float x, float y);
t_pos					sg_posi(int x, int y);
t_size					sg_sizef(float w, float h);
t_size					sg_sizei(int w, int h);
t_rect					sg_rectf(float x, float y, float w, float h);
t_rect					sg_recti(int x, int y, int w, int h);
t_rect					sg_rect(t_pos pos, t_size size);

void					sg_align_bounds(t_rect *bounds, int alignement);

void					sg_rect_to_vec2buf(t_rect rect, float *buf);
int						sg_is_in_rect(t_rect rect, t_pos pos);

t_color					sg_colorf(float r, float g, float b, float a);
t_color					sg_colori(int r, int g, int b, int a);
t_color					sg_color(int hexcolor);

void					sg_uniform_color(GLuint uniform, t_color color);
void					sg_uniform_rect(GLuint uniform, t_rect bounds);

GLuint					get_shader_prog(char const *fs_file,
							char const *vs_file);

void					*sg_new_gstr(char const *str,
							char const *font_file, int size);
void					sg_del_gstr(void *gstr_ptr);

void					sg_draw_gstr(void *gstr, t_color color, t_pos pos);

void					sg_del_all_gstr(void);

#endif
