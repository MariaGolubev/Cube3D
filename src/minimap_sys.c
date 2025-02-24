/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_sys.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:37:35 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_box(mlx_image_t *image, t_vec2 pos, t_u32 size, t_u32 color)
{
	t_u32	x;
	t_u32	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (pos.x + x > 0 && pos.y + y > 0 && pos.x + x < image->width
				&& pos.y + y < image->height)
				mlx_put_pixel(image, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

static void	clean_image(t_image *image)
{
	ft_memset(image->image->pixels, 30, image->image->width
		* image->image->height * 4);
}

static void	draw_map(t_image *image, t_map *map, t_vec2 offset)
{
	t_u32	x;
	t_u32	y;
	t_vec2	box_pos;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			box_pos = vec2_add(vec2_scale(vec2(x, y), 10), offset);
			if (map_get(map, x, y) == MAP_WALL)
				draw_box(image->image, box_pos, 10, 0xFFFFFF80);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_image *image, t_camera *camera, t_vec2 minimap_center)
{
	t_u32	x;
	t_ray	ray;
	t_vec2	box_pos;

	draw_box(image->image, vec2_sub(minimap_center, vec2(2, 2)), 4, 0xFF000080);
	x = 0;
	while (x < camera->width)
	{
		ray = camera_ray_gen(camera, x);
		box_pos = vec2_add(vec2_sub(minimap_center, vec2(2, 2)),
				vec2_scale(ray.direction, 10));
		draw_box(image->image, box_pos, 2, from_rgba(0, 255, 0, 128));
		x += camera->width / 10;
	}
}

t_u64	minimap_system(t_app *app)
{
	t_map		*map;
	t_camera	*camera;
	t_image		*img;
	t_vec2		minimap_center;
	t_vec2		offset;

	map = app_source_get(app, "map");
	camera = app_source_get(app, "camera");
	img = app_source_get(app, "minimap");
	minimap_center = vec2(img->image->width / 2, img->image->height / 2);
	offset = vec2_sub(minimap_center, vec2_scale(camera->position, 10));
	clean_image(img);
	draw_map(img, map, offset);
	draw_player(img, camera, minimap_center);
	return (EVENT_NONE_MSK);
}
