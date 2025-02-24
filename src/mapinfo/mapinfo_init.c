/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 12:31:58 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/01 16:30:35 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

int	mapinfo_init(t_mapinfo *mapinfo)
{
	mapinfo->c_color = NULL;
	mapinfo->f_color = NULL;
	mapinfo->no_path = NULL;
	mapinfo->so_path = NULL;
	mapinfo->we_path = NULL;
	mapinfo->ea_path = NULL;
	mapinfo->map = NULL;
	mapinfo->camera_pos = vec2(-1, -1);
	mapinfo->camera_dir = 0;
	mapinfo->is_allocated = false;
	return (0);
}
