/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:45:53 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/05 10:24:53 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

t_map	*map_new(t_u32 width, t_u32 height)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map_init(map, width, height);
	map->is_allocated = true;
	return (map);
}
