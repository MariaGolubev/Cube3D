/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_sys.c                                     :+:    :+:            */
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

static t_vec2	position_with_collision(t_camera *camera, t_vec2 magnitu,
		t_map *map)
{
	t_vec2	new_pos;
	t_vec2	direction;

	direction = vec2_rotate(magnitu, atan2(camera->direction.y,
				camera->direction.x));
	new_pos = vec2_add(camera->position, direction);
	if (map_get(map, floor(new_pos.x), floor(camera->position.y)) == 1
		&& map_get(map, floor(camera->position.x), floor(new_pos.y)) == 1)
		return (camera->position);
	if (map_get(map, floor(new_pos.x), floor(new_pos.y)) != 0)
	{
		if (map_get(map, floor(camera->position.x), floor(new_pos.y)) == 0)
			new_pos = vec2(camera->position.x, new_pos.y);
		else if (map_get(map, floor(new_pos.x), floor(camera->position.y)) == 0)
			new_pos = vec2(new_pos.x, camera->position.y);
		else
			return (camera->position);
	}
	return (new_pos);
}

t_u64	mouse_rotate_system(t_app *app)
{
	t_camera		*camera;
	t_f64			delta_time;
	static t_i32	old_mous_x;
	t_i32			mous_x;
	t_i32			moux_y;

	if (*(t_u8 *)app_source_get(app, "is_mouse") == 0)
		return (EVENT_NONE_MSK);
	mlx_get_mouse_pos(app->mlx, &mous_x, &moux_y);
	camera = app_source_get(app, "camera");
	delta_time = app_get_delta_time(app);
	if (old_mous_x == 0)
		old_mous_x = mous_x;
	if (mous_x != old_mous_x)
	{
		camera_rotate(camera, (mous_x - old_mous_x) * MOUSE_ROTATE_SPEED
			* delta_time);
		mlx_set_mouse_pos(app->mlx, app_get_width(app) / 2, app_get_height(app)
			/ 2);
		old_mous_x = app_get_width(app) / 2;
		return (EVENT_DRAW_MSK);
	}
	else
		old_mous_x = mous_x;
	return (EVENT_NONE_MSK);
}

static t_vec2	getdir(t_kstate *keys_state)
{
	t_vec2	direction;

	direction = vec2(0, 0);
	if (keys_state->move_forward)
		direction = vec2(1.0, 0.0);
	else if (keys_state->move_back)
		direction = vec2(-1.0, 0.0);
	if (keys_state->move_right)
		direction = vec2_add(direction, vec2(0.0, 1.0));
	else if (keys_state->move_left)
		direction = vec2_add(direction, vec2(0.0, -1.0));
	return (direction);
}

t_u64	move_system(t_app *app)
{
	t_camera	*camera;
	t_kstate	*ks;
	t_map		*map;
	t_vec2		direction;
	t_f64		delta_time;

	camera = app_source_get(app, "camera");
	ks = app_source_get(app, "keys_state");
	map = app_source_get(app, "map");
	delta_time = app_get_delta_time(app);
	direction = getdir(ks);
	if (ks->rotate_right)
		camera_rotate(camera, ROTATE_SPEED * delta_time);
	else if (ks->rotate_left)
		camera_rotate(camera, -ROTATE_SPEED * delta_time);
	if (vec2_length(direction) != 0)
	{
		direction = vec2_normalize(direction);
		direction = vec2_scale(direction, MOVE_SPEED * delta_time);
		camera_set_position(camera, position_with_collision(camera, direction,
				map));
	}
	if (vec2_length(direction) != 0 || ks->rotate_left || ks->rotate_right)
		return (EVENT_DRAW_MSK);
	return (EVENT_NONE_MSK);
}
