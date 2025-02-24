/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_set_aspect_ratio.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:49:46 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:49:47 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_set_aspect_ratio(t_camera *camera, t_u32 width, t_u32 height)
{
	double	aspect_ratio;
	double	plane_x;

	camera->width = width;
	aspect_ratio = (double)width / (double)height;
	plane_x = tan((camera->fov / 2.0) * (M_PI / 180.0)) * aspect_ratio;
	camera->plane = vec2(-camera->direction.y * plane_x, camera->direction.x
			* plane_x);
}
