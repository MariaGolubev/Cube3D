/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_parse_map.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 13:45:09 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 20:53:48 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

static void	get_map_size(char *str, t_u32 *width, t_u32 *height)
{
	char	**lines;
	size_t	len;
	t_u32	i;

	lines = ft_split(str, '\n');
	i = 0;
	*width = 0;
	*height = 0;
	while (lines[i] != NULL)
	{
		len = ft_strlen(lines[i]);
		if (*width < len)
			*width = len;
		(*height)++;
		free(lines[i]);
		i++;
	}
	free(lines);
}

static int	fill_camera(t_mapinfo *mapinfo, t_vec2 pos, const char dir)
{
	if (mapinfo->camera_pos.x != -1 || mapinfo->camera_pos.y != -1)
		return (1);
	mapinfo->camera_pos = vec2_add(pos, vec2(0.5, 0.5));
	if (dir == 'N')
		mapinfo->camera_dir = -M_PI_2;
	else if (dir == 'S')
		mapinfo->camera_dir = M_PI_2;
	else if (dir == 'W')
		mapinfo->camera_dir = M_PI;
	else if (dir == 'E')
		mapinfo->camera_dir = 0;
	return (0);
}

static int	fill_row(t_mapinfo *mapinfo, t_u32 y, char *line)
{
	t_u32	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == ' ')
			map_set(mapinfo->map, x, y, MAP_EMPTY);
		else if (line[x] == '1')
			map_set(mapinfo->map, x, y, MAP_WALL);
		else if (line[x] == '0')
			map_set(mapinfo->map, x, y, MAP_EMPTY);
		else if (line[x] == 'N' || line[x] == 'S' || line[x] == 'W'
			|| line[x] == 'E')
		{
			map_set(mapinfo->map, x, y, MAP_EMPTY);
			if (fill_camera(mapinfo, vec2(x, y), line[x]) != 0)
				return (MAPINFO_CAMERA_NOT_UNIQUE_ERROR);
		}
		else
			return (MAPINFO_MAP_CHAR_ERROR);
		x++;
	}
	while (x < mapinfo->map->width)
		map_set(mapinfo->map, x++, y, MAP_EMPTY);
	return (MAPINFO_SUCCESS);
}

static int	destroy_end_return(t_mapinfo *mapinfo, int status)
{
	map_destroy(mapinfo->map);
	mapinfo->map = NULL;
	return (status);
}

int	parse_map(t_mapinfo *mapinfo, char *str)
{
	t_u32	width;
	t_u32	height;
	char	*line;
	t_u32	y;
	int		status;

	get_map_size(str, &width, &height);
	mapinfo->map = map_new(width, height);
	if (mapinfo->map == NULL)
		return (1);
	y = 0;
	while (str != NULL)
	{
		if (str[0] == '\n')
			return (destroy_end_return(mapinfo, MAPINFO_MAP_EMPTY_LINE_ERROR));
		line = ft_strtok_r(NULL, "\n", &str);
		if (line == NULL)
			break ;
		status = fill_row(mapinfo, y, line);
		if (status != 0)
			return (destroy_end_return(mapinfo, status));
		y++;
	}
	return (0);
}
