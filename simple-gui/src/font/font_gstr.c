/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_gstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 04:55:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 04:55:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./font.h"

t_gstr						*sg_get_gstr(void *data)
{
	return ((t_gstr *)((t_llist *)data)->data);
}

static void					del_gstr_data(void *data)
{
	t_gstr					*gstr;
	t_glyph					*glyphs;

	gstr = (t_gstr *)data;
	glyphs = gstr->glyphs;
	while (glyphs->buffer)
	{
		free(glyphs->buffer);
		glyphs++;
	}
	free(gstr->glyphs);
	free(gstr);
}

void						sg_del_gstr(void *gstr_ptr)
{
	t_llist					*gstr;

	gstr = (t_llist *)gstr_ptr;
	ft_llist_rem(&(get_font_manager()->gstrs), gstr, &del_gstr_data);
}

void						sg_del_all_gstr(void)
{
	ft_llist_del(&(get_font_manager()->gstrs), &del_gstr_data);
}
