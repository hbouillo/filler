/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:20:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:23:37 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H

# include "../p_sg.h"

typedef struct				s_font_manager
{
	FT_Library				ft;
	t_llist					*gstrs;
}							t_font_manager;

typedef struct				s_font_renderer
{
	int						init;
	GLuint					shader;
	GLuint					vao;
	GLuint					tex;
}							t_font_renderer;

t_font_manager				*get_font_manager(void);

#endif
