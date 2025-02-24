/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_validate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 22:21:42 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"
#include "cub3d.h"

static int	path_validate(const char *path, int not_found_error)
{
	int	fd;

	if (path == NULL)
		return (not_found_error);
	if (check_path(path, ".png"))
		return (MAPINFO_PATH_EXT_ERROR);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (MAPINFO_PATH_OPEN_ERROR);
	close(fd);
	return (MAPINFO_SUCCESS);
}

int	mapinfo_validate(t_mapinfo *mapinfo)
{
	int	status;

	errno = 0;
	if (mapinfo->c_color == NULL)
		return (MAPINFO_C_COLOR_NOT_FOUND_ERROR);
	if (mapinfo->f_color == NULL)
		return (MAPINFO_F_COLOR_NOT_FOUND_ERROR);
	status = path_validate(mapinfo->no_path, MAPINFO_NO_PATH_NOT_FOUND_ERROR);
	if (status != MAPINFO_SUCCESS)
		return (status);
	status = path_validate(mapinfo->so_path, MAPINFO_SO_PATH_NOT_FOUND_ERROR);
	if (status != MAPINFO_SUCCESS)
		return (status);
	status = path_validate(mapinfo->we_path, MAPINFO_WE_PATH_NOT_FOUND_ERROR);
	if (status != MAPINFO_SUCCESS)
		return (status);
	status = path_validate(mapinfo->ea_path, MAPINFO_EA_PATH_NOT_FOUND_ERROR);
	if (status != MAPINFO_SUCCESS)
		return (status);
	if (mapinfo->camera_pos.x == -1 || mapinfo->camera_pos.y == -1)
		return (MAPINFO_CAMERA_NOT_FOUND_ERROR);
	if (mapinfo->map == NULL)
		return (MAPINFO_MAP_NOT_FOUND_ERROR);
	return (flood_fill(mapinfo->map, mapinfo->camera_pos));
}
