/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_destroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:48:27 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/31 00:58:41 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

void	map_destroy(t_map *map)
{
	if (map == NULL)
		return ;
	free(map->array);
	map->array = NULL;
	map->width = 0;
	map->height = 0;
	if (map->is_allocated)
		free(map);
}
