/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_parse_from_str.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 12:32:34 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 20:45:59 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

static int	iscontains(const char *str, char *strs[])
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		ft_strncmp(str, strs[i], ft_strlen(strs[i]));
		if (ft_strncmp(str, strs[i], ft_strlen(strs[i])) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

static int	parse_elements(t_mapinfo *minfo, char *s)
{
	int	status;

	status = 0;
	while (s != NULL && status == 0)
	{
		s = s + ft_strspn(s, "\n");
		if (ft_strncmp(s, "NO", 2) == 0)
			status = parse_path(&minfo->no_path, ft_strtok_r(NULL, "\n", &s));
		else if (ft_strncmp(s, "SO", 2) == 0)
			status = parse_path(&minfo->so_path, ft_strtok_r(NULL, "\n", &s));
		else if (ft_strncmp(s, "WE", 2) == 0)
			status = parse_path(&minfo->we_path, ft_strtok_r(NULL, "\n", &s));
		else if (ft_strncmp(s, "EA", 2) == 0)
			status = parse_path(&minfo->ea_path, ft_strtok_r(NULL, "\n", &s));
		else if (ft_strncmp(s, "C", 1) == 0)
			status = parse_color(&minfo->c_color, ft_strtok_r(NULL, "\n", &s));
		else if (ft_strncmp(s, "F", 1) == 0)
			status = parse_color(&minfo->f_color, ft_strtok_r(NULL, "\n", &s));
		else if (iscontains(s, (char *[]){"F", "C", "NO", "SO", "WE", "EA",
				NULL}) == 0)
			return (parse_map(minfo, s));
	}
	return (status);
}

int	mapinfo_parse_from_str(t_mapinfo *mapinfo, char *str)
{
	int	status;

	errno = 0;
	status = parse_elements(mapinfo, str);
	if (status == 0)
		status = mapinfo_validate(mapinfo);
	if (status != 0)
	{
		mapinfo_destroy(mapinfo);
		return (status);
	}
	return (MAPINFO_SUCCESS);
}
