/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_sys.c                                      :+:    :+:            */
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

static t_texture	*get_wall_texture(t_app *app, t_ray_out hit_out)
{
	static t_texture	*textures[4] = {NULL};
	t_vec2				relative;

	if (textures[0] == NULL)
	{
		textures[0] = app_source_get(app, N_TEXTURE);
		textures[1] = app_source_get(app, S_TEXTURE);
		textures[2] = app_source_get(app, W_TEXTURE);
		textures[3] = app_source_get(app, E_TEXTURE);
	}
	relative = vec2_sub(hit_out.hit_point, hit_out.hit_map);
	if (relative.y == 1)
		return (textures[0]);
	else if (relative.y == 0)
		return (textures[1]);
	else if (relative.x == 1)
		return (textures[2]);
	return (textures[3]);
}

static inline t_f64	get_offset_x(t_ray_out ray_out)
{
	t_vec2	relativ;

	relativ = vec2_sub(ray_out.hit_point, ray_out.hit_map);
	if (relativ.x == 0.0)
		return (relativ.y);
	else if (relativ.x == 1.0)
		return (1.0 - relativ.y);
	else if (relativ.y == 0.0)
		return (1.0 - relativ.x);
	else
		return (relativ.x);
}

static inline t_f64	get_offset_y(t_i32 start, t_i32 end, t_i32 y)
{
	return ((t_f64)(y - start) / (t_f64)(end - start));
}

static inline void	draw_column(mlx_image_t *image, t_texture *texture,
		t_ray_out ray_out, t_u32 x)
{
	t_f64	distance;
	t_i32	start;
	t_i32	end;
	t_i32	y;
	t_f64	gradient;

	distance = vec2_distance(ray_out.camera_position, ray_out.hit_point);
	distance *= vec2_dot(ray_out.direction, ray_out.camera_diretion);
	start = (image->height / 2) - (image->height / (2 * distance));
	end = (image->height / 2) + (image->height / (2 * distance));
	y = imax(start, 0);
	gradient = fmin(1.0, 1.0 / distance);
	while (y <= imin(end, image->height - 1))
	{
		mlx_put_pixel(image, x, y, mix(0x000000FF, texture_get_pixel(texture,
					get_offset_x(ray_out), get_offset_y(start, end, y)),
				gradient));
		y++;
	}
}

t_u64	raycast_system(t_app *app)
{
	t_u32		x;
	t_camera	*camera;
	t_map		*map;
	t_ray_out	ray_out;
	t_image		*walls_img;

	map = app_source_get(app, "map");
	camera = app_source_get(app, "camera");
	walls_img = app_source_get(app, "walls");
	ft_bzero(walls_img->image->pixels, walls_img->image->width
		* walls_img->image->height * 4);
	x = 0;
	while (x < camera->width)
	{
		if (dda_ray_cast(camera_ray_gen(camera, x), map, &ray_out,
				RAYCAST_SYS_MAX_ITER))
		{
			draw_column(walls_img->image, get_wall_texture(app, ray_out),
				ray_out, x);
		}
		x++;
	}
	return (EVENT_NONE_MSK);
}
