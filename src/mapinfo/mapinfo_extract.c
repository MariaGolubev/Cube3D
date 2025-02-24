/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_extract.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 12:58:49 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 21:10:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

t_u32	*mapinfo_extract_celling(t_mapinfo *mapinfo)
{
	t_u32	*celling_color;

	celling_color = mapinfo->c_color;
	mapinfo->c_color = NULL;
	return (celling_color);
}

t_u32	*mapinfo_extract_floor(t_mapinfo *mapinfo)
{
	t_u32	*floor_color;

	floor_color = mapinfo->f_color;
	mapinfo->f_color = NULL;
	return (floor_color);
}

t_map	*mapinfo_extract_map(t_mapinfo *mapinfo)
{
	t_map	*map;

	map = mapinfo->map;
	mapinfo->map = NULL;
	return (map);
}
