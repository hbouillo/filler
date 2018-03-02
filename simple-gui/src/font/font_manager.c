/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:27:20 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 05:25:44 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./font.h"

t_font_manager				*get_font_manager(void)
{
	static t_font_manager	font_manager;

	if (!font_manager.ft)
	{
		if (FT_Init_FreeType(&(font_manager.ft)))
			return (NULL);
	}
	return (&font_manager);
}

static void					update_glyph_size(t_size *size, t_glyph glyph)
{
	float					fx;
	float					fy;

	fx = 2.0 / (float)sg_get_shared_data()->window_w;
	fy = 2.0 / (float)sg_get_shared_data()->window_h;
	size->w += (float)(glyph.advance_x) * fx / 64.0;
	size->h = ((float)(glyph.hori_bearing_y) * fy / 64.0 > size->h
		? (float)(glyph.hori_bearing_y) * fy / 64.0 : size->h);
}

static void					fill_glyph(t_glyph *glyph, FT_GlyphSlot slot)
{
	size_t					size;

	size = sizeof(char) * slot->bitmap.rows * slot->bitmap.width;
	if (!(glyph->buffer = (char *)ft_memalloc(size)))
		return ;
	ft_memcpy(glyph->buffer, slot->bitmap.buffer, size);
	glyph->rows = slot->bitmap.rows;
	glyph->width = slot->bitmap.width;
	glyph->hori_bearing_x = slot->metrics.horiBearingX;
	glyph->hori_bearing_y = slot->metrics.horiBearingY;
	glyph->height = slot->metrics.height;
	glyph->advance_x = slot->advance.x;
	glyph->advance_y = slot->advance.y;
}

void						*sg_new_gstr(char const *str,
								char const *font_file, int size)
{
	t_llist					*new;
	t_gstr					*gstr;
	FT_Face					face;
	int						index;

	if (!str || !font_file || size < 0)
		return (NULL);
	if (!(gstr = (t_gstr *)ft_memalloc(sizeof(t_gstr))) ||
		!(gstr->glyphs = (t_glyph *)ft_memalloc(
			sizeof(t_glyph) * (ft_strlen(str) + 1))))
		return (NULL);
	FT_New_Face(get_font_manager()->ft, font_file, 0, &face);
	FT_Set_Pixel_Sizes(face, 0, size);
	index = -1;
	while (str[++index])
	{
		FT_Load_Char(face, str[index], FT_LOAD_RENDER);
		fill_glyph(gstr->glyphs + index, face->glyph);
		update_glyph_size(&(gstr->size), gstr->glyphs[index]);
	}
	new = ft_llist_new(gstr);
	ft_llist_front(&(get_font_manager()->gstrs), new);
	return (new);
}

void						sg_resize_gstr(void *gstr_ptr)
{
	t_shared				*shared;
	float					fx;
	float					fy;
	t_gstr					*gstr;

	shared = sg_get_shared_data();
	gstr = sg_get_gstr(gstr_ptr);
	fx = ((float)shared->last_window_w) / ((float)shared->window_w);
	fy = ((float)shared->last_window_h) / ((float)shared->window_h);
	gstr->size.w *= fx;
	gstr->size.h *= fy;
}
