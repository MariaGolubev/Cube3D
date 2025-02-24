/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:37:35 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cub3d.h"
#include "dda_raycast.h"
#include "mapinfo.h"
#include <stdio.h>

inline t_u32	from_rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a)
{
	return (((t_u32)r << 24) | ((t_u32)g << 16) | ((t_u32)b << 8) | ((t_u32)a));
}

inline t_u32	mix(t_u32 color1, t_u32 color2, t_f64 ratio)
{
	t_u32	r;
	t_u32	g;
	t_u32	b;
	t_u32	a;

	r = (t_u32)(((color1 & 0xFF000000) >> 24) * (1.0 - ratio)
			+ ((color2 & 0xFF000000) >> 24) * ratio);
	g = (t_u32)(((color1 & 0x00FF0000) >> 16) * (1.0 - ratio)
			+ ((color2 & 0x00FF0000) >> 16) * ratio);
	b = (t_u32)(((color1 & 0x0000FF00) >> 8) * (1.0 - ratio)
			+ ((color2 & 0x0000FF00) >> 8) * ratio);
	a = (t_u32)((color1 & 0x000000FF) * (1.0 - ratio) + (color2 & 0x000000FF)
			* ratio);
	return (from_rgba(r, g, b, a));
}

inline t_i32	imax(t_i32 a, t_i32 b)
{
	if (a > b)
		return (a);
	return (b);
}

inline t_i32	imin(t_i32 a, t_i32 b)
{
	if (a < b)
		return (a);
	return (b);
}

inline t_u32	texture_get_pixel(mlx_texture_t *texture, t_f64 offset_x,
		t_f64 offset_y)
{
	t_i32	x;
	t_i32	y;
	t_u32	clr;

	x = offset_x * (texture->width - 1);
	y = offset_y * (texture->height - 1);
	clr = 0;
	clr |= ((t_u32)texture->pixels[y * texture->width * 4 + x * 4 + 0]) << 24;
	clr |= ((t_u32)texture->pixels[y * texture->width * 4 + x * 4 + 1]) << 16;
	clr |= ((t_u32)texture->pixels[y * texture->width * 4 + x * 4 + 2]) << 8;
	clr |= ((t_u32)texture->pixels[y * texture->width * 4 + x * 4 + 3]);
	return (clr);
}
