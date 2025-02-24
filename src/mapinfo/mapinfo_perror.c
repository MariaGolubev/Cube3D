/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_perror.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 14:02:07 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 13:59:04 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

const char	**mapinfo_error_strings(void)
{
	static const char	*errors[18];

	if (errors[0] == NULL)
	{
		errors[MAPINFO_SUCCESS] = "Success";
		errors[MAPINFO_MALLOC_ERROR] = "Malloc error";
		errors[MAPINFO_COLOR_ERROR] = "Color error";
		errors[MAPINFO_C_COLOR_NOT_FOUND_ERROR] = "C color not found error";
		errors[MAPINFO_F_COLOR_NOT_FOUND_ERROR] = "F color not found error";
		errors[MAPINFO_PATH_ERROR] = "Path error";
		errors[MAPINFO_PATH_EXT_ERROR] = "Path ext error";
		errors[MAPINFO_PATH_OPEN_ERROR] = "Path open error";
		errors[MAPINFO_NO_PATH_NOT_FOUND_ERROR] = "NO path not found error";
		errors[MAPINFO_SO_PATH_NOT_FOUND_ERROR] = "SO path not found error";
		errors[MAPINFO_WE_PATH_NOT_FOUND_ERROR] = "WE path not found error";
		errors[MAPINFO_EA_PATH_NOT_FOUND_ERROR] = "EA path not found error";
		errors[MAPINFO_CAMERA_NOT_FOUND_ERROR] = "Camera not found error";
		errors[MAPINFO_CAMERA_NOT_UNIQUE_ERROR] = "Camera not unique error";
		errors[MAPINFO_MAP_CHAR_ERROR] = "Map char error";
		errors[MAPINFO_MAP_EMPTY_LINE_ERROR] = "Map empty line error";
		errors[MAPINFO_MAP_FLOOD_FILL_ERROR] = "Map flood fill error";
		errors[MAPINFO_MAP_NOT_FOUND_ERROR] = "Map not found error";
	}
	return (errors);
}

int	mapinfo_perror(int status)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(mapinfo_error_strings()[status], 2);
	return (status);
}
