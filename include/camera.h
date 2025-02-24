/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:36:25 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:38:58 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "types.h"
# include "vector.h"
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_camera
{
	t_vec2	position;
	t_vec2	direction;
	t_vec2	plane;
	t_u32	width;
	t_f64	fov;
	bool	is_allocated;
}			t_camera;

void		camera_init(t_camera *camera, t_vec2 position, t_f64 fov);
t_camera	*camera_new(t_vec2 position, t_f64 fov);
void		camera_destroy(t_camera *camera);
void		camera_rotate(t_camera *camera, t_f64 angle);
void		camera_move(t_camera *camera, t_vec2 direction);
void		camera_set_position(t_camera *camera, t_vec2 position);
void		camera_set_aspect_ratio(t_camera *camera, t_u32 w, t_u32 h);

#endif
