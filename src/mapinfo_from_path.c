/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_from_path.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 12:34:08 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/24 19:42:28 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*read_map(const char *path)
{
	int		fd;
	char	*file_content;

	file_content = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = ft_read_to_str(fd);
	if (file_content == NULL)
	{
		close(fd);
		return (NULL);
	}
	return (file_content);
}

static void	load_textures(t_app *app, t_mapinfo *mapinfo)
{
	app_source_add(app, N_TEXTURE, mlx_load_png(mapinfo->no_path),
		(t_del_fn)mlx_delete_texture);
	app_source_add(app, S_TEXTURE, mlx_load_png(mapinfo->so_path),
		(t_del_fn)mlx_delete_texture);
	app_source_add(app, W_TEXTURE, mlx_load_png(mapinfo->we_path),
		(t_del_fn)mlx_delete_texture);
	app_source_add(app, E_TEXTURE, mlx_load_png(mapinfo->ea_path),
		(t_del_fn)mlx_delete_texture);
}

static void	load_camera(t_app *app, t_mapinfo *mapinfo)
{
	t_camera	*camera;

	camera = camera_new(mapinfo->camera_pos, 50);
	if (camera == NULL)
		exiterr(app, "Could not create camera", false, 2);
	camera_set_aspect_ratio(camera, app_get_width(app), app_get_height(app));
	camera_rotate(camera, mapinfo->camera_dir);
	app_source_add(app, "camera", camera, (t_del_fn)camera_destroy);
}

static void	load_map(t_app *app, t_mapinfo *mapinfo)
{
	app_source_add(app, "celling_color", mapinfo_extract_celling(mapinfo),
		free);
	app_source_add(app, "floor_color", mapinfo_extract_floor(mapinfo), free);
	app_source_add(app, "map", mapinfo_extract_map(mapinfo),
		(t_del_fn)map_destroy);
}

void	mapinfo_from_path(t_app *app, const char *path)
{
	char		*file_content;
	t_mapinfo	*mapinfo;
	int			status;

	if (check_path(path, ".cub"))
		exiterr(app, "Error\nInvalid map file", false, 1);
	mapinfo = mapinfo_new();
	if (mapinfo == NULL)
		exiterr(app, "Could not create mapinfo", false, 2);
	file_content = read_map(path);
	if (file_content == NULL)
		exiterr(app, "Could not create mapinfo", false, 2);
	status = mapinfo_parse_from_str(mapinfo, file_content);
	free(file_content);
	if (status != 0)
	{
		app_destroy(app);
		exit(mapinfo_perror(status));
	}
	app_source_add(app, "mapinfo", mapinfo, (t_del_fn)mapinfo_destroy);
	load_textures(app, mapinfo);
	load_camera(app, mapinfo);
	load_map(app, mapinfo);
}
