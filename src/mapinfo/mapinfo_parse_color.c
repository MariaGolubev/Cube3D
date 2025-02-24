/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapinfo_parse_color.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 13:27:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/13 15:27:20 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"
#include <stdio.h>

static int	parse_element(char **str, t_u8 *color, const char ch)
{
	long	value;

	value = ft_strtol(*str, str, 10);
	if (value < 0 || value > 255)
		return (1);
	while (ft_isspace(**str))
		(*str)++;
	if (**str != ch)
		return (1);
	if (**str != '\0')
		(*str)++;
	*color = (t_u8)value;
	return (0);
}

int	parse_color(t_u32 **color, char *str)
{
	t_u8	r;
	t_u8	g;
	t_u8	b;

	str += 2;
	if (parse_element(&str, &r, ',') || parse_element(&str, &g, ',')
		|| parse_element(&str, &b, '\0'))
		return (MAPINFO_COLOR_ERROR);
	if (ft_strtok_r(NULL, "", &str) != NULL)
		return (MAPINFO_COLOR_ERROR);
	*color = ft_calloc(1, sizeof(t_u32));
	if (*color == NULL)
		return (MAPINFO_MALLOC_ERROR);
	**color = from_rgba(r, g, b, 255);
	return (MAPINFO_SUCCESS);
}
