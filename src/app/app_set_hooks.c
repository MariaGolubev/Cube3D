/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_set_hooks.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:33:31 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/18 20:34:36 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static void	exit_hook(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	mlx_close_window(app->mlx);
}

static void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (height > MAX_HEIGHT)
		height = MAX_HEIGHT;
	if (width > MAX_WIDTH)
		width = MAX_WIDTH;
	if (height <= 0)
		height = 1;
	if (width <= 0)
		width = 1;
	mlx_resize_image(app->image, width, height);
	storage_add(&app->storage, "image", app->image, NULL);
	sysmanager_add_event(&app->sysmanager, EVENT_RESIZE_MSK);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_app			*app;
	t_keyhook_fn	keyhook;
	t_u64			event;

	app = (t_app *)param;
	keyhook = hashtable_search(&app->keyhooks, keydata.key);
	if (keyhook)
	{
		event = keyhook(app, (t_key_action)keydata.action);
		if ((event & EVENT_EXIT_MSK) != 0)
		{
			mlx_close_window(app->mlx);
			return ;
		}
		sysmanager_add_event(&app->sysmanager, event);
	}
}

static void	loop_hook(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (sysmanager_run(&app->sysmanager, app) & EVENT_EXIT_MSK)
		mlx_close_window(app->mlx);
}

void	app_set_hooks(t_app *app)
{
	mlx_close_hook(app->mlx, exit_hook, app);
	mlx_resize_hook(app->mlx, resize_hook, app);
	mlx_key_hook(app->mlx, key_hook, app);
	mlx_loop_hook(app->mlx, loop_hook, app);
}
