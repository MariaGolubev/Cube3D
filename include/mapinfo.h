/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 11:35:57 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 14:18:12 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPINFO_H
# define MAPINFO_H
# include "libft.h"
# include "queue.h"
# include "types.h"
# include "vector.h"
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_map_char
{
	MAP_ERR = -1,
	MAP_EMPTY = 0,
	MAP_WALL = 1,
}			t_mapv;

typedef enum e_mapinfo_error
{
	MAPINFO_SUCCESS = 0,
	MAPINFO_MALLOC_ERROR,
	MAPINFO_COLOR_ERROR,
	MAPINFO_C_COLOR_NOT_FOUND_ERROR,
	MAPINFO_F_COLOR_NOT_FOUND_ERROR,
	MAPINFO_PATH_ERROR,
	MAPINFO_PATH_EXT_ERROR,
	MAPINFO_PATH_OPEN_ERROR,
	MAPINFO_NO_PATH_NOT_FOUND_ERROR,
	MAPINFO_SO_PATH_NOT_FOUND_ERROR,
	MAPINFO_WE_PATH_NOT_FOUND_ERROR,
	MAPINFO_EA_PATH_NOT_FOUND_ERROR,
	MAPINFO_CAMERA_NOT_FOUND_ERROR,
	MAPINFO_CAMERA_NOT_UNIQUE_ERROR,
	MAPINFO_MAP_CHAR_ERROR,
	MAPINFO_MAP_EMPTY_LINE_ERROR,
	MAPINFO_MAP_FLOOD_FILL_ERROR,
	MAPINFO_MAP_NOT_FOUND_ERROR,
}			t_mapinfo_error;

typedef struct s_map
{
	t_u32	width;
	t_u32	height;
	t_u8	*array;
	bool	is_allocated;
}			t_map;

typedef struct s_mapinfo
{
	t_u32	*c_color;
	t_u32	*f_color;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_map	*map;
	t_vec2	camera_pos;
	t_f64	camera_dir;
	bool	is_allocated;
}			t_mapinfo;

void		map_destroy(t_map *map);
int			map_init(t_map *map, t_u32 width, t_u32 height);
t_map		*map_new(t_u32 width, t_u32 height);
t_mapv		map_get(t_map *map, t_i32 x, t_i32 y);
void		map_set(t_map *map, t_u32 x, t_u32 y, t_mapv value);

int			mapinfo_init(t_mapinfo *mapinfo);
t_mapinfo	*mapinfo_new(void);
int			mapinfo_parse_from_str(t_mapinfo *mapinfo, char *str);
void		mapinfo_destroy(t_mapinfo *mapinfo);
int			mapinfo_perror(int status);
int			mapinfo_validate(t_mapinfo *mapinfo);

t_u32		*mapinfo_extract_celling(t_mapinfo *mapinfo);
t_u32		*mapinfo_extract_floor(t_mapinfo *mapinfo);
t_map		*mapinfo_extract_map(t_mapinfo *mapinfo);

t_u32		from_rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);

int			parse_color(t_u32 **color, char *str);
int			parse_path(char **path, char *str);
int			parse_map(t_mapinfo *mapinfo, char *str);

int			flood_fill(t_map *map, t_vec2 pos);

#endif
