/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc_keyhooks.c                                    :+:    :+:            */
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

t_u64	exit_keyhook(t_app *app, t_key_action action)
{
	(void)app;
	(void)action;
	return (EVENT_EXIT_MSK);
}

t_u64	mouse_focused_keyhook(t_app *app, t_key_action action)
{
	t_u8	*is_mouse;

	is_mouse = app_source_get(app, "is_mouse");
	(void)app;
	if (action == KEY_PRESS)
		*is_mouse = !(*is_mouse);
	if (*is_mouse)
	{
		app_set_cursor_mode(app, CURSOR_HIDDEN);
		mlx_set_mouse_pos(app->mlx, app_get_width(app) / 2, app_get_height(app)
			/ 2);
	}
	else
		app_set_cursor_mode(app, CURSOR_NORMAL);
	return (EVENT_NONE_MSK);
}
