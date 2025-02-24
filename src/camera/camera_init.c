/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:41:02 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:41:56 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_init(t_camera *camera, t_vec2 position, t_f64 fov)
{
	camera->position = position;
	camera->direction = vec2(1, 0);
	camera->fov = fov;
	camera->plane = vec2(0, tan((fov / 2.0) * (M_PI / 180.0)));
	camera->is_allocated = false;
}
