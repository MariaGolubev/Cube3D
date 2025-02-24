/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize_sys.c                                       :+:    :+:            */
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

t_u64	resize_system(t_app *app)
{
	t_camera	*camera;
	t_image		*walls;

	camera = app_source_get(app, "camera");
	walls = app_source_get(app, "walls");
	camera_set_aspect_ratio(camera, app_get_width(app), app_get_height(app));
	mlx_resize_image(walls->image, app_get_width(app), app_get_height(app));
	return (EVENT_DRAW_MSK);
}
