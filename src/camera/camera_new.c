/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:40:45 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:43:37 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	*camera_new(t_vec2 position, t_f64 fov)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		return (NULL);
	camera_init(camera, position, fov);
	camera->is_allocated = true;
	return (camera);
}
