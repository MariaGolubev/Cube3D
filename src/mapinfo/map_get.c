/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_get.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:35:56 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

t_mapv	map_get(t_map *map, t_i32 x, t_i32 y)
{
	if (x < 0 || x >= (t_i32)map->width || y < 0 || y >= (t_i32)map->height)
	{
		return (-1);
	}
	return (map->array[y * map->width + x]);
}
