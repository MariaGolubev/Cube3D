/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hit_point.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 11:41:25 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/10 11:42:19 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dda_raycast.h"

static t_vec2	get_hit_point_vertical(t_vec2 map_pos, t_ray ray)
{
	t_vec2	hit_point;
	double	t;

	if (ray.direction.y > 0)
	{
		t = (map_pos.y - ray.origin.y) / ray.direction.y;
		hit_point.y = map_pos.y;
		hit_point.x = ray.origin.x + t * ray.direction.x;
	}
	else
	{
		t = (map_pos.y + 1 - ray.origin.y) / ray.direction.y;
		hit_point.y = map_pos.y + 1;
		hit_point.x = ray.origin.x + t * ray.direction.x;
	}
	return (hit_point);
}

static t_vec2	get_hit_point_horizontal(t_vec2 map_pos, t_ray ray)
{
	t_vec2	hit_point;
	double	t;

	if (ray.direction.x > 0)
	{
		t = (map_pos.x - ray.origin.x) / ray.direction.x;
		hit_point.x = map_pos.x;
		hit_point.y = ray.origin.y + t * ray.direction.y;
	}
	else
	{
		t = (map_pos.x + 1 - ray.origin.x) / ray.direction.x;
		hit_point.x = map_pos.x + 1;
		hit_point.y = ray.origin.y + t * ray.direction.y;
	}
	return (hit_point);
}

t_vec2	get_hit_point(bool is_y_side, t_vec2 map_pos, t_ray ray)
{
	if (is_y_side)
		return (get_hit_point_vertical(map_pos, ray));
	else
		return (get_hit_point_horizontal(map_pos, ray));
}
