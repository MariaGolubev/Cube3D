/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:37:35 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:12 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cub3d.h"
#include "dda_raycast.h"
#include "mapinfo.h"
#include <stdio.h>

static void	add_systems(t_app *app)
{
	app_system_add(app, resize_system, EVENT_RESIZE_MSK);
	app_system_add(app, draw_cf_system, EVENT_RESIZE_MSK);
	app_system_add(app, mouse_rotate_system, EVENT_ALWAYS_MSK);
	app_system_add(app, move_system, EVENT_ALWAYS_MSK);
	app_system_add(app, raycast_system, EVENT_DRAW_MSK);
	app_system_add(app, minimap_system, EVENT_DRAW_MSK);
}

static void	add_keyhooks(t_app *app)
{
	app_keyhook_add(app, MLX_KEY_ESCAPE, exit_keyhook);
	app_keyhook_add(app, MLX_KEY_SPACE, mouse_focused_keyhook);
	set_move_keyhooks(app);
	set_rotate_keyhooks(app);
}

static void	add_sources(t_app *app, t_image *walls, t_image *minimap)
{
	app_source_add(app, "walls", walls, (t_del_fn)image_destroy);
	app_source_add(app, "minimap", minimap, (t_del_fn)image_destroy);
	app_source_add(app, "keys_state", ft_calloc(1, sizeof(t_kstate)), free);
	app_source_add(app, "is_mouse", ft_calloc(1, sizeof(t_u8)), free);
}

int	main(int argc, char *argv[])
{
	t_app	app;
	int		status;
	t_image	*minimap_img;
	t_image	*walls_img;

	if (argc != 2)
		return (ft_putendl_fd("Error\n./cub3D <path to .cub>", 2), 1);
	status = app_init(&app, DEFAULT_WIDTH, DEFAULT_HEIGHT, "cub3D");
	if (status != 0)
		return (ft_putendl_fd("Error\n MLX init error", 2), status);
	minimap_img = app_image_new(&app, 300, 300);
	walls_img = app_image_new(&app, app_get_width(&app), app_get_height(&app));
	app_image_to_window(&app, walls_img, 0, 0);
	app_image_to_window(&app, minimap_img, 5, 5);
	add_sources(&app, walls_img, minimap_img);
	add_systems(&app);
	mapinfo_from_path(&app, argv[1]);
	add_keyhooks(&app);
	app_event_add(&app, EVENT_RESIZE_MSK);
	app_run(&app);
	app_destroy(&app);
	return (0);
}
