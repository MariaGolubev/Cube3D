/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_destroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:31:52 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 14:07:42 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_destroy(t_app *app)
{
	storage_destroy(&app->storage);
	hashtable_destroy(&app->keyhooks, NULL);
	mlx_delete_image(app->mlx, app->image);
	mlx_close_window(app->mlx);
	mlx_terminate(app->mlx);
}
