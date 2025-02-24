/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:44:06 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:45:43 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_move(t_camera *camera, t_vec2 direction)
{
	direction = vec2_rotate(direction, atan2(camera->direction.y,
				camera->direction.x));
	camera->position = vec2_add(camera->position, direction);
}
