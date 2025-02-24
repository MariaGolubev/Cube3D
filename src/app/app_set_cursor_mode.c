/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_set_cursor_mode.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 20:31:13 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/24 20:32:50 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_set_cursor_mode(t_app *app, t_cursor_mode mode)
{
	mlx_set_cursor_mode(app->mlx, (mouse_mode_t)mode);
}
