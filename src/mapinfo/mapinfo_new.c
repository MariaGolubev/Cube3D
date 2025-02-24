/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 14:12:58 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 14:13:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

t_mapinfo	*mapinfo_new(void)
{
	t_mapinfo	*mapinfo;

	mapinfo = ft_calloc(1, sizeof(t_mapinfo));
	if (mapinfo == NULL)
		return (NULL);
	mapinfo_init(mapinfo);
	mapinfo->is_allocated = true;
	return (mapinfo);
}
