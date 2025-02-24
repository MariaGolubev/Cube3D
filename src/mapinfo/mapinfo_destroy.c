/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_destroy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 21:52:38 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 14:12:38 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

void	mapinfo_destroy(t_mapinfo *mapinfo)
{
	free(mapinfo->c_color);
	free(mapinfo->f_color);
	free(mapinfo->no_path);
	free(mapinfo->so_path);
	free(mapinfo->we_path);
	free(mapinfo->ea_path);
	map_destroy(mapinfo->map);
	if (mapinfo->is_allocated)
		free(mapinfo);
}
