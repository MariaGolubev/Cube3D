/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_cf_sys.c                                      :+:    :+:            */
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

static void	draw_ceiling(t_app *app, t_u32 color, t_u32 y)
{
	t_u32	x;
	t_f64	gradient;

	x = 0;
	gradient = (t_f64)y / (t_f64)(app_get_height(app) / 2);
	while (x < app_get_width(app))
	{
		mlx_put_pixel(app->image, x, y, mix(color, 0x000000FF, gradient));
		x++;
	}
}

static void	draw_floor(t_app *app, t_u32 color, t_u32 y)
{
	t_u32	x;
	t_f64	gradient;

	x = 0;
	gradient = 1.0 - (t_f64)(y - (t_f64)app_get_height(app) / 2)
		/ (t_f64)(app_get_height(app) / 2);
	while (x < app_get_width(app))
	{
		mlx_put_pixel(app->image, x, y, mix(color, 0x000000FF,
				gradient));
		x++;
	}
}

t_u64	draw_cf_system(t_app *app)
{
	t_u32	*ceiling_color;
	t_u32	*floor_color;
	t_u32	y;

	ceiling_color = app_source_get(app, "celling_color");
	floor_color = app_source_get(app, "floor_color");
	y = 0;
	while (y < app_get_height(app) / 2)
	{
		draw_ceiling(app, *ceiling_color, y);
		y++;
	}
	while (y < app_get_height(app))
	{
		draw_floor(app, *floor_color, y);
		y++;
	}
	return (EVENT_NONE_MSK);
}
