/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_raycast.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 10:37:09 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 16:27:10 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_RAYCAST_H
# define DDA_RAYCAST_H
# include "camera.h"
# include "mapinfo.h"
# include "types.h"
# include "vector.h"
# include <stdlib.h>

typedef struct s_ray
{
	t_vec2	origin;
	t_vec2	direction;
	t_vec2	camera_direction;
}			t_ray;

typedef struct s_ray_out
{
	t_vec2	hit_map;
	t_vec2	hit_point;
	t_vec2	direction;
	t_vec2	camera_position;
	t_vec2	camera_diretion;
}			t_ray_out;

bool		dda_ray_cast(t_ray ray, t_map *map, t_ray_out *out, t_u8 max_i);
t_ray		camera_ray_gen(t_camera *camera, t_u32 x);

t_vec2		get_hit_point(bool is_y_side, t_vec2 map_pos, t_ray ray);

#endif
