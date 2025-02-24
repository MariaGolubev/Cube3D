/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:48:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/05 10:24:58 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

int	map_init(t_map *map, t_u32 width, t_u32 height)
{
	map->width = width;
	map->height = height;
	map->array = (t_u8 *)ft_calloc(width * height, sizeof(t_u8));
	if (map->array == NULL)
		return (MAPINFO_MALLOC_ERROR);
	map->is_allocated = false;
	return (MAPINFO_SUCCESS);
}
