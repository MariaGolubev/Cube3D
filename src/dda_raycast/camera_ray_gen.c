/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_ray_gen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 19:56:17 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/11 20:03:45 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dda_raycast.h"

t_ray	camera_ray_gen(t_camera *camera, t_u32 x)
{
	t_ray	ray;
	t_vec2	plane_offset;

	plane_offset = vec2_scale(camera->plane, (2 * x / (t_f64)camera->width
				- 1));
	ray.origin = camera->position;
	ray.direction = vec2_normalize(vec2_add(camera->direction, plane_offset));
	ray.camera_direction = camera->direction;
	return (ray);
}
