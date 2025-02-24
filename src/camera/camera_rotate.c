/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:45:59 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:46:01 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_rotate(t_camera *camera, t_f64 angle)
{
	camera->direction = vec2_rotate(camera->direction, angle);
	camera->plane = vec2_rotate(camera->plane, angle);
}
