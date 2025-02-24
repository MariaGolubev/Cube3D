/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:43:44 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:43:54 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_destroy(t_camera *camera)
{
	if (camera->is_allocated)
		free(camera);
}
