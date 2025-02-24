/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:32:28 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/18 20:34:38 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static int	init_keyhooks(t_app *app)
{
	if (hashtable_init(&app->keyhooks, 100) != 0)
	{
		mlx_delete_image(app->mlx, app->image);
		mlx_terminate(app->mlx);
		return (1);
	}
	return (0);
}

static int	init_storage(t_app *app)
{
	if (storage_init(&app->storage, 100) != 0)
	{
		hashtable_destroy(&app->keyhooks, NULL);
		mlx_delete_image(app->mlx, app->image);
		mlx_terminate(app->mlx);
		return (1);
	}
	return (0);
}

static int	init_sysmanager(t_app *app)
{
	if (sysmanager_init(&app->sysmanager) != 0)
	{
		storage_destroy(&app->storage);
		hashtable_destroy(&app->keyhooks, NULL);
		mlx_delete_image(app->mlx, app->image);
		mlx_terminate(app->mlx);
		return (1);
	}
	return (0);
}

int	app_init(t_app *app, t_i32 width, t_i32 height, const char *title)
{
	app->mlx = mlx_init(width, height, title, true);
	if (app->mlx == NULL)
		return (1);
	app->image = mlx_new_image(app->mlx, width, height);
	if (app->image == NULL)
	{
		mlx_terminate(app->mlx);
		return (2);
	}
	if (mlx_image_to_window(app->mlx, app->image, 0, 0) == -1)
	{
		mlx_delete_image(app->mlx, app->image);
		mlx_terminate(app->mlx);
		return (3);
	}
	if (init_keyhooks(app) != 0 || init_storage(app) != 0
		|| init_sysmanager(app) != 0)
		return (4);
	app_source_add(app, "mlx", app->mlx, NULL);
	app_source_add(app, "image", app->image, NULL);
	app_set_hooks(app);
	return (0);
}
