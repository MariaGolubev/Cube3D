/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_set_position.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 17:46:23 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:46:25 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_set_position(t_camera *camera, t_vec2 position)
{
	camera->position = position;
}
