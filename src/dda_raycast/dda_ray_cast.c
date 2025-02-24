/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_ray_cast.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 10:44:11 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/11 20:04:36 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dda_raycast.h"

static t_vec2	get_delta_dist(t_ray ray)
{
	t_vec2	delta_dist;

	delta_dist.x = sqrt(1 + (ray.direction.y * ray.direction.y)
			/ (ray.direction.x * ray.direction.x));
	delta_dist.y = sqrt(1 + (ray.direction.x * ray.direction.x)
			/ (ray.direction.y * ray.direction.y));
	return (delta_dist);
}

static t_vec2	get_side_dist(t_ray ray, t_vec2 map_pos, t_vec2 delta_dist)
{
	t_vec2	side_dist;

	if (ray.direction.x < 0)
		side_dist.x = (ray.origin.x - map_pos.x) * delta_dist.x;
	else
		side_dist.x = (map_pos.x + 1.0 - ray.origin.x) * delta_dist.x;
	if (ray.direction.y < 0)
		side_dist.y = (ray.origin.y - map_pos.y) * delta_dist.y;
	else
		side_dist.y = (map_pos.y + 1.0 - ray.origin.y) * delta_dist.y;
	return (side_dist);
}

static t_vec2	get_step(t_ray ray)
{
	t_vec2	step;

	if (ray.direction.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray.direction.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

static bool	perform_dda_step(t_vec2 *side_dist, t_vec2 *map_pos,
		t_vec2 delta_dist, t_vec2 step)
{
	if (side_dist->x < side_dist->y)
	{
		side_dist->x += delta_dist.x;
		map_pos->x += step.x;
	}
	else
	{
		side_dist->y += delta_dist.y;
		map_pos->y += step.y;
	}
	return (true);
}

bool	dda_ray_cast(t_ray ray, t_map *map, t_ray_out *out_hit, t_u8 max_eval)
{
	t_vec2	map_pos;
	t_vec2	delta_dist;
	t_vec2	side_dist;
	t_vec2	step;
	bool	is_y_side;

	map_pos = vec2((t_i32)ray.origin.x, (t_i32)ray.origin.y);
	delta_dist = get_delta_dist(ray);
	side_dist = get_side_dist(ray, map_pos, delta_dist);
	step = get_step(ray);
	while (max_eval-- > 0)
	{
		is_y_side = side_dist.x > side_dist.y;
		perform_dda_step(&side_dist, &map_pos, delta_dist, step);
		if (map_get(map, map_pos.x, map_pos.y) != 0)
		{
			out_hit->camera_position = ray.origin;
			out_hit->camera_diretion = ray.camera_direction;
			out_hit->hit_map = map_pos;
			out_hit->hit_point = get_hit_point(is_y_side, map_pos, ray);
			out_hit->direction = ray.direction;
			return (true);
		}
	}
	return (false);
}
