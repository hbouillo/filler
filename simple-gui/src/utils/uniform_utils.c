/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 23:59:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/17 16:54:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sg.h"

void				sg_uniform_color(GLuint uniform, t_color color)
{
	glUniform4f(uniform, color.r, color.g, color.b, color.a);
}

void				sg_uniform_rect(GLuint uniform, t_rect bounds)
{
	glUniform4f(uniform, bounds.x, bounds.y, bounds.w, bounds.h);
}
