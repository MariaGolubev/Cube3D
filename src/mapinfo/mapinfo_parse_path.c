/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_parse_path.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 13:30:18 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 21:09:36 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

int	parse_path(char **path, char *str)
{
	char	*p;

	if (*path != NULL)
		return (MAPINFO_PATH_ERROR);
	str += 2;
	p = ft_strtok_r(NULL, " \t", &str);
	if (p == NULL || ft_strtok_r(NULL, "", &str) != NULL)
		return (MAPINFO_PATH_ERROR);
	*path = ft_strdup(p);
	return (0);
}
