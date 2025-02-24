/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 16:00:47 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/05 10:08:58 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

void	map_set(t_map *map, t_u32 x, t_u32 y, t_mapv value)
{
	map->array[y * map->width + x] = value;
}
